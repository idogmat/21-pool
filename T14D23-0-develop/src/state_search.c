#include "state_search.h"
#include "binary_files_common_functions.h"

static char *path;

int main(int argc, char *argv[]) {
    int ok = 0;
    char *fin = malloc(COUNT * sizeof(char));
    char *tmp = malloc(COUNT * sizeof(char));
    int day, mon, year;
    struct my_struct record;

    path = malloc(COUNT * sizeof(char));
    if (argc != 0) {
        strcpy(path, argv[0]);
        clearpath();
        strcpy(tmp, path);
    }

    if (getfile(&fin)) {
        ok = readdate(&day, &mon, &year);
        if (ok) {
            record.day = day;
            record.month = mon;
            record.year = year;
            ok = searchrec(fin, record);
            if (ok >0) {
                printf("%d", ok);
            } else {
                printf("n/a");
            }
        } else {
            printf("n/a");
        }

    } else {
        printf("n/a");
    }

    free(tmp);
    free(path);
    free(fin);
    return 1;
}

int readdate(int *day, int *mon, int *year) {
    int ok = 0;

    if (scanf("%2d.%2d.%4d", day, mon, year) && *day > 0 && *day <= 31
    && *mon > 0 && *mon <= 12 && *year > 0) {
        ok = 1;
    }
    return ok;
}

int searchrec(char *fin, struct my_struct record) {
    int ok = 0;
    FILE *file;
    struct my_struct rec;

    file = fopen(fin, "rb");
    if (file != NULL) {
        fseek(file, 0, SEEK_END);
        long pos = ftell(file);
        if (pos > 0) {
            fseek(file, 0, SEEK_SET);
            for (int i = 0; i < get_records_count_in_file(file); i++) {
                rec = read_record_from_file(file, i);
                if (record.day == rec.day && record.month == rec.month && record.year == rec.year) {
                    ok = rec.code;
                }
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
    strcat(tmp, "../");
}
