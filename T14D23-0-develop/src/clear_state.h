#ifndef SRC_CLEAR_STATE_H_
#define SRC_CLEAR_STATE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <unistd.h>
#include "binary_files_common_functions.h"
#define COUNT 500

int readdate(int *day1, int *mon1, int *year1, int *day2, int *mon2, int *year2);
int searchrec(char *fin, struct my_struct record1, struct my_struct record2, int *first, int *last);
int getfile(char **fin);
void clearpath();
int delinterval(char *fin, struct my_struct record1, struct my_struct record2);
int datachek(struct my_struct rec1, struct my_struct rec2);
int datachekshort(struct my_struct rec1, struct my_struct rec2);
int sortbubble(FILE *file);
int sort(char *fin);
void swap(int *day1, int *mon1, int *year1, int *day2, int *mon2, int *year2);

#endif  // SRC_CLEAR_STATE_H_
