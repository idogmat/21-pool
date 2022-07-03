#ifndef SRC_STATE_SEARCH_H_
#define SRC_STATE_SEARCH_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_files_common_functions.h"
#define COUNT 500

int readdate(int *day, int *mon, int *year);
int searchrec(char *fin, struct my_struct record);
int getfile(char **fin);
void clearpath();

#endif  // SRC_STATE_SEARCH_H_
