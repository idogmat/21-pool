
#ifndef SRC_LIST_H_
#define SRC_LIST_H_
#include "door_struct.h"

struct node {
    struct door data;
    struct node *next;
};

void print_struct(struct door* door);
struct node* init(struct door*door);
struct node* add_door(struct node* elem, struct door*door);
struct node* find_door(int door_id, struct node* root);
struct node* remove_door(struct node* elem, struct node* root);
void destroy(struct node* root);
void print_node(struct node* node);
#endif    //    SRC_LIST_H_
