#include <stdio.h>
#include "door_struct.h"


void bubble(struct door* doors, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (doors[j].id > doors[j+1].id) {
                int tmp = doors[j].id;
                doors[j].id = doors[j+1].id;
                doors[j+1].id = tmp;
           }
       }
    }
}

void close_doors(struct door* doors, int n) {
    for (int i = 0; i < n; i++) {
        doors[i].status = 0;
    }
}

void open_doors(struct door* doors, int n) {
    for (int i = 0; i < n; i++) {
        doors[i].status = 1;
    }
}

void print_arr(struct door* doors, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d, ", doors[i].id);
        printf("%d", doors[i].status);
        if (i != n - 1) {
            printf("\n");
        }
    }
}
