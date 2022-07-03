#ifndef SRC_STATE_SORT_H_
#define SRC_STATE_SORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <time.h>
#include "binary_files_common_functions.h"
#define COUNT 500


int getfile(char** fin);
int case0(char *fin);
int case1(char *fin);
int case2(char *fin);
int read_print(FILE *file);
int sortbubble(FILE *file);
int datachek(struct my_struct rec1, struct my_struct rec2);
int write_file(FILE *file);
void clearpath();

#endif  // SRC_STATE_SORT_H_
