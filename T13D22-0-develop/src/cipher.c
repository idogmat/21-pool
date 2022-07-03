// "Copyright [2022] <Jeseniam>"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logger.h"
#define ENG 26

void clearAllH(char* a);
void encrypt(char*a, int n);

int main() {
    char* name = malloc(1000*sizeof(char));
    FILE *fp;
    char res[1000];
    char str[1000];
    int err = 0;
    int oper = 1;
    while ((oper != -1 && err != 1) || (oper == 1 && err != 1)
    || (oper == 2 && err != 1) || (oper == 3 && err != 1)) {
        scanf("%d", &oper);
        if (oper == 1) {
        scanf("%s", name);
        int i = 0;
            while (name[i] != '\0') {
                res[i] = name[i];
                i++;
            }
        if ((fp = fopen(res, "r")) == NULL) {
            printf("n/a\n");
            log_init(name, "n/a", 0);
        } else {
            fp = fopen(res, "r");
            if (getc(fp) == EOF) {
                printf("n/a\n");
                log_init(name, "n/a", 0);
                fclose(fp);
            } else {
                while (fgets(str, 100, fp) != NULL) {
                    printf("%s", str);
                }
            log_init(name, str, 1);
            printf("\n");
            fclose(fp);
        }
        }
        } else if (oper == 2) {
            scanf("%s", name);
            if ((fp = fopen(res, "r")) == NULL) {
            log_init(name, "n/a", 0);
            printf("n/a\n");
        } else {
            fp = fopen(res, "r");
            if (getc(fp) == EOF) {
                printf("n/a\n");
                log_init(name, "n/a", 0);
                fclose(fp);
            } else {
            fp = fopen(res, "a");
                while (fgets(str, 100, fp) != NULL) {
                    printf("%s", str);
                }
            logcat(res, name, 1);
            fprintf(fp, "%s", name);
            fclose(fp);
            fp = fopen(res, "r");
            while (fgets(str, 100, fp) != NULL) {
                printf("%s", str);
            }
            printf("\n");
            fclose(fp);
            }
         }
        } else if (oper == 3) {
            int k;
            if (scanf("%d", &k)) {
                FILE *test;
                char elh1[100]="../src/ai_modules/m1.h";
                char elh2[100]="../src/ai_modules/m2.h";
                test = fopen(elh1, "w");
                fclose(test);
                test = fopen(elh2, "w");
                fclose(test);
                char elc1[100]="../src/ai_modules/m1.c";
                char elc2[100]="../src/ai_modules/m2.c";
                encrypt(elc1, k);
                encrypt(elc2, k);
                Cezar_joke();
            }
        } else if (oper == -1) {
            log_close(name);
        } else {
           err = 1;
        }
    }
    if (oper < -1 || oper > 3 || oper == 0) {
        printf("n/a");
    }
    free(name);
    return 0;
}

void encrypt(char*a, int n) {
    FILE *fp1;
    fp1 = fopen(a, "r");
    char arr[1000];
    int flag;
    char c;
    int i = 0;
    c = getc(fp1);
    while (!feof(fp1)) {
        flag = 0;
        if (c >= 'A' && c <= 'Z') {
            c = c + (n % ENG);
            if (c > 'Z') c = 'A' + (c - 'Z') - 1;
            arr[i] = c;
            i++;
            flag = 1;
        }
        if (c >= 'a' && c <= 'z') {
            c = c + (n % ENG);
            if (c > 'z') c = 'a' + (c - 'z') - 1;
            arr[i] = c;
            i++;
            flag = 1;
        }
        if (!flag) {
            arr[i] = c;
            i++;
        }
        c = getc(fp1);
    }
    fclose(fp1);
    fp1 = fopen(a, "w");
    fprintf(fp1, "%s", arr);
    fclose(fp1);
}
