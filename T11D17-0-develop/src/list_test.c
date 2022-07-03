#include "list.h"
int main() {
    struct door door1 = { 1, 0 };
    struct door door2 = { 1, 1 };
    struct door door3 = { 1, 1 };
    struct node* node1 = init(&door1);
    add_door(node1, &door2);
    if (add_door(node1->next, &door3)->data.id == door3.id) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
    printf("\n");
    if (remove_door(node1->next, node1)->data.id == door1.id) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
    destroy(node1);
    node1 = NULL;
    return 0;
}
