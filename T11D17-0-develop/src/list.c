#include "list.h"

struct node* init(struct door*door) {
    struct node* A = malloc(sizeof(struct node));
    A->data.id = door->id;
    A->data.status = door->status;
    A->next = NULL;
    return A;
}
struct node* add_door(struct node* elem, struct door*door) {
    if (elem != NULL) {
        struct node * p = elem->next;
        struct node * new = malloc(sizeof(struct node));
        new->data.id = door->id;
        new->data.status = door->status;
        new->next = p;
        elem->next = new;
    }
    return elem;
}

struct node* find_door(int door_id, struct node* root) {
    if (root != NULL) {
        while (root->next != NULL && root->data.id != door_id) {
            root = root->next;
        }
    }
    return root;
}
void destroy(struct node* root) {
    while (root != NULL) {
        struct node* p = root->next;
        free(root);
        root = p;
    }
}

struct node* remove_door(struct node* elem, struct node* root) {
    struct node* result = NULL;
    if (root != elem) {
        struct node* list = NULL;
        list = root->next;
        if (list->data.id == elem->data.id && list->next == elem->next) {
            root->next = elem->next;
            free(elem);
            elem = NULL;
            result = root;
        } else {
            list = remove_door(elem, root->next);
            result = list;
        }
    } else {
        result = root->next;
        free(root);
    }
    return result;
}

void print_struct(struct door* door) {
        printf("%d ", door->id);
        printf("%d", door->status);
}
void print_node(struct node* root) {
        printf("%d ", root->data.id);
        printf("%d", root->data.status);
        printf("\n");
        if (root->next != NULL) print_node(root->next);
}
