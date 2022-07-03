#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "state_sort.h"
#include "binary_files_common_functions.h"

static char *path;

int main(int argc, char *argv[]) {
    int key = 0, ok = 0;  // flag1 = 0;
    char *fin = malloc(COUNT * sizeof(char));
    char *tmp = malloc(COUNT * sizeof(char));

    path = malloc(COUNT * sizeof(char));
    if (argc != 0) {
        strcpy(path, argv[0]);
        clearpath();
        strcpy(tmp, path);
    }

    if (getfile(&fin)) {
        while (key != -1) {
            if (scanf("%d", &key)) {
                switch (key) {
                    case 0:
                        ok = case0(fin);
                        if (ok != 1) {
                            printf("n/a\n");
                        }
//                        if (ok == 0)
//                            key = -1;
                        break;
                    case 1:
                        ok = case1(fin);
                        if (ok != 1) {
                            printf("n/a\n");
                        }
//                        if (ok == 0)
//                            key = -1;
                        break;
                    case 2:
                        ok = case2(fin);
                        if (ok != 1) {
                            printf("n/a\n");
                        }
//                        if (ok == 0)
//                            key = -1;
                        break;
                    case -1:
                        break;
                    default:
                        printf("n/a\n");
                        break;
                }
            } else {
                printf("n/a\n");
                fflush(stdin);   //  очистка буфера ввода
//            while (getchar() != '\n') {   // собрали все лишнее из строки
//            }
            }
        }
    } else {
        printf("n/a\n");
    }
    free(tmp);
    free(path);
    free(fin);
    return 0;
}

int case0(char *fin) {
    int ok = 0;
    FILE *file;

    file = fopen(fin, "rb");
    if (file != NULL) {
        fseek(file, 0, SEEK_END);
        long pos = ftell(file);
        if (pos > 0) {
            fseek(file, 0, SEEK_SET);
            ok = read_print(file);
//            printf("\n");
        } else {
            ok = 2;   // файл пуст
        }
    } else {
            ok = 0;    // нет файла
    }
    fclose(file);
    return ok;
}

int case1(char *fin) {
    int ok = 0;
    FILE *file;

    file = fopen(fin, "r+b");
    if (file != NULL) {
        fseek(file, 0, SEEK_END);
        long pos = ftell(file);
        if (pos > 0) {
            fseek(file, 0, SEEK_SET);
            ok = sortbubble(file);
            ok = read_print(file);
        } else {
            ok = 2;   // файл пуст
        }
    } else {
            ok = 0;    // нет файла
    }
    fclose(file);
    return ok;
}

int case2(char *fin) {
    int ok = 0;
    FILE *file;

    file = fopen(fin, "r+b");
    if (file != NULL) {
        ok = write_file(file);
        ok = sortbubble(file);
        ok = read_print(file);
    }

    fclose(file);
    return ok;
}

int read_print(FILE *file) {
    int ok = 0;
    struct my_struct record;

    for (int i = 0; i < get_records_count_in_file(file); i++) {
            record = read_record_from_file(file, i);
        printf("%d %d %d %d %d %d %d %d \n", record.year, record.month,
               record.day, record.hour, record.min, record.sec, record.status, record.code);
        }
        ok = 1;

    return ok;
}


int sortbubble(FILE *file) {
    int ok = 0, n = get_records_count_in_file(file);
    struct my_struct record1, record2;

    for (int i = 0 ; i < n; i++) {
           // сравниваем два соседних элемента.
        for (int j = 0 ; j < n - i ; j++) {
            record1 = read_record_from_file(file, j);
            record2 = read_record_from_file(file, j+1);
            if (datachek(record1, record2) > 0) {
             // если они идут в неправильном порядке, то
             //  меняем их местами.
                swap_records_in_file(file, j, j+1);
            }
        }
    }
    return ok;
}

int datachek(struct my_struct rec1, struct my_struct rec2) {
    int res = 0;

    if (rec1.year == rec2.year) {
        if (rec1.month == rec2.month) {
            if (rec1.day == rec2.day) {
                if (rec1.hour == rec2.hour) {
                    if (rec1.min == rec2.min) {
                        res = rec1.sec - rec2.sec;
                    } else {
                        res = rec1.min - rec2.min;
                    }
                } else {
                    res = rec1.hour - rec2.hour;
                }
            } else {
                res = rec1.day - rec2.day;
            }
        } else {
            res = rec1.month- rec2.month;
        }
    } else {
        res = rec1.year - rec2.year;
    }
    return res;
}

int write_file(FILE *file) {
    int ok = 0;
    struct my_struct record;

    if (scanf("%d%d%d%d%d%d%d%d", &record.year, &record.month, &record.day,
              &record.hour, &record.min, &record.sec, &record.status, &record.code)) {
        write_record_in_file(file, &record, get_records_count_in_file(file));
        ok = 1;
    }

    return ok;
}

int getfile(char** fin) {
    int ok = 0;
    char *tmp = malloc(COUNT * sizeof(char));

    if (scanf("%s", *fin)) {
        ok = 1;
        strcpy(tmp, path);
        strcat(tmp, *fin);
        strcpy(*fin, tmp);
    }
    free(tmp);
    return ok;
}

void clearpath() {
    char *tmp = path;

    tmp = strrchr(path, '/');
    *(tmp+1) = '\0';
    strcat(tmp, "../");
}
