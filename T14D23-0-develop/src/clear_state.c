#include "clear_state.h"
#include "binary_files_common_functions.h"

static char *path;

int main(int argc, char *argv[]) {
    int ok = 0;
    char *fin = malloc(COUNT * sizeof(char));
    int day1, mon1, year1, day2, mon2, year2;
    struct my_struct record1, record2;

    path = malloc(COUNT * sizeof(char));
    if (argc != 0) {
        strcpy(path, argv[0]);
        clearpath();
    }

    if (getfile(&fin)) {
        ok = readdate(&day1, &mon1, &year1, &day2, &mon2, &year2);
        if (ok) {
            record1.day = day1;
            record1.month = mon1;
            record1.year = year1;
            record2.day = day2;
            record2.month = mon2;
            record2.year = year2;
            ok = sort(fin);
            ok = delinterval(fin, record1, record2);

            if (ok <= 0)
                printf("n/a");
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
    free(path);
    free(fin);
    return 0;
}

int readdate(int *day1, int *mon1, int *year1, int *day2, int *mon2, int *year2) {
    int ok = 0;

    if (scanf("%2d.%2d.%4d%2d.%2d.%4d", day1, mon1, year1, day2, mon2, year2)
        && *day1 > 0 && *day1 <= 31 && *mon1 > 0 && *mon1 <= 12 && *year1 > 0
        && *day2 > 0 && *day2 <= 31 && *mon2 > 0 && *mon2 <= 12 && *year2 > 0) {
        ok = 1;
    }
    if (*year1 > *year2)
        swap(day1, mon1, year1, day2, mon2, year2);
    else if (*year1 == *year2 && *mon1 > *mon2)
        swap(day1, mon1, year1, day2, mon2, year2);
    else if (*year1 == *year2 && *mon1 == *mon2 && *day1 > *day2)
        swap(day1, mon1, year1, day2, mon2, year2);
    return ok;
}

int getfile(char **fin) {
    int ok = 0;
    FILE *file;
    char *tmp = malloc(COUNT * sizeof(char));

    scanf("%s", *fin);
    strcpy(tmp, path);
    strcat(tmp, *fin);
    strcpy(*fin, tmp);
    file = fopen(*fin, "rb");
    if (file != NULL && get_file_size_in_bytes(file) > 0) {   // существует и не пустой
        ok = 1;
    }
    fclose(file);
    free(tmp);
    return ok;
}

void clearpath() {
    char *tmp = path;

    tmp = strrchr(path, '/');
    *(tmp+1) = '\0';
    strcat(path, "../");
}

int sort(char *fin) {
    int ok = 0;
    FILE *file;

    file = fopen(fin, "r+b");
    if (file != NULL) {
        fseek(file, 0, SEEK_END);
        long pos = ftell(file);
        if (pos > 0) {
            fseek(file, 0, SEEK_SET);
            ok = sortbubble(file);
  //          ok = read_print(file);
        } else {
            ok = 2;   // файл пуст
        }
    } else {
            ok = 0;    // нет файла
        }
        fclose(file);
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
            res = rec1.month - rec2.month;
        }
    } else {
        res = rec1.year - rec2.year;
    }
    return res;
}

int datachekshort(struct my_struct rec1, struct my_struct rec2) {
    int res = 0;

    if (rec1.year == rec2.year) {
        if (rec1.month == rec2.month) {
            res = rec1.day - rec2.day;
        } else {
            res = rec1.month - rec2.month;
        }
    } else {
        res = rec1.year - rec2.year;
    }
    return res;
}

int delinterval(char *fin, struct my_struct record1, struct my_struct record2) {
    int pos1, pos2, i, ok = 0;
    size_t delsize, newsize;
    FILE *file;
    struct my_struct record;

    ok = searchrec(fin, record1, record2, &pos1, &pos2);
    if (ok > 0) {
        ok = 1;
        file = fopen(fin, "r+b");

        for (i = 0; pos2 + 1 + i < get_records_count_in_file(file); i++) {
            record = read_record_from_file(file, pos2+1+i);
            write_record_in_file(file, &record, pos1+i);
        }

//    record = read_record_from_file(file, pos1-1+i);   // последний
//    printf("%d %d %d %d %d %d %d %d \n", record.year,
//     record.month,  record.day, record.hour, record.min, record.sec, record.status, record.code);
//    record = read_record_from_file(file, pos1-2+i);   // предпоследний
//    printf("%d %d %d %d %d %d %d %d \n", record.year,
//     record.month,  record.day, record.hour, record.min, record.sec, record.status, record.code);

        delsize = (pos2 - pos1 + 1) * sizeof(struct my_struct);
        newsize = get_file_size_in_bytes(file) - delsize;
        ftruncate(fileno(file), newsize);
        if (ftruncate(fileno(file), newsize) != 0)
            ok = 0;
        fclose(file);
    }
    return ok;
}

int searchrec(char *fin, struct my_struct record1, struct my_struct record2, int *first, int *last) {
    int ok = 1, i;
    FILE *file;
    struct my_struct rec;

    file = fopen(fin, "rb");
    if (file != NULL) {
        fseek(file, 0, SEEK_END);
        long pos = ftell(file);
        if (pos > 0) {
            fseek(file, 0, SEEK_SET);

            rec = read_record_from_file(file, 0);
            for (i = 0; i < get_records_count_in_file(file) && datachekshort(rec, record1) < 0; i++) {
                rec = read_record_from_file(file, i);
            }
            *first = i - 1;
            if (*first < 0)
                *first = 0;
            for (i = *first; i <= get_records_count_in_file(file) && datachekshort(rec, record2) <= 0; i++) {
                rec = read_record_from_file(file, i);
            }
            *last = i - 2;
            if (*first >= get_records_count_in_file(file) || *last < 0) {
                ok = 0;
            }

        } else {
            ok = -2;   // файл пуст
        }
    } else {
            ok = -1;    // нет файла
    }
    fclose(file);
    return ok;
}

void swap(int *day1, int *mon1, int *year1, int *day2, int *mon2, int *year2) {
    int d, m, y;

    d = *day1;
    m = *mon1;
    y = *year1;
    *day1 = *day2;
    *mon1 = *mon2;
    *year1 = *year2;
    *day2 = d;
    *mon2 = m;
    *year2 = y;
}
