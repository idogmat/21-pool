#ifndef SRC_DOOR_STRUCT_H_
#define SRC_DOOR_STRUCT_H_
#include <stdio.h>
#include <stdlib.h>
struct door{
    int id;
    int status;
};

void bubble(struct door* doors, int n);
void print_arr(struct door* doors, int n);
void close_doors(struct door* doors, int n);
void open_doors(struct door* doors, int n);

#endif    //    SRC_DOOR_STRUCT_H_
