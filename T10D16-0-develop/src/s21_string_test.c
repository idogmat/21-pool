
#include <stdio.h>
#include "s21_string.h"
void s21_strcat_test(char *str1, char *str2);
void s21_strcmp_test(char *str1, char *str2);
void s21_strlen_test(char *str, int y);
void s21_strcpy_test(char *str1, char *str2);
void s21_strchr_test(char *str, char ch, int x);
void s21_strstr_test(char *str, char* substr);
int main() {
char check1[100] = "string";
char check2[100] = "boo lean";
char check3[100] = "function";
char check4[100] = "func12tion";
#ifdef STRLEN
s21_strlen_test(check1, 6);
printf("\n");
s21_strlen_test(check2, 8);
printf("\n");
s21_strlen_test(check3, 9);
printf("\n");
s21_strlen_test(check4, 10);
#endif
#ifdef STRCMP
s21_strcmp_test(check1, check2);
printf("\n");
s21_strcmp_test(check1, check4);
printf("\n");
s21_strcmp_test(check1, check3);
#endif
#ifdef STRCPY
s21_strcpy_test(check1, check2);
printf("\n");
s21_strcpy_test(check1, check4);
printf("\n");
s21_strcpy_test(check1, check3);
#endif
#ifdef STRCAT
s21_strcat_test(check1, check2);
printf("\n");
s21_strcat_test(check2, check4);
printf("\n");
s21_strcat_test(check4, check3);
#endif
#ifdef STRCHR
s21_strchr_test(check1, 't', 1);
printf("\n");
s21_strchr_test(check2, 'o', 1);
printf("\n");
s21_strchr_test(check4, 'x', 5);
printf("\n");
s21_strchr_test(check3, 'f', 3);
#endif
#ifdef STRSTR
char test1[5] = "ing";
char test2[5] = "boo";
char test3[5] = "ion";
s21_strstr_test(check1, test1);
printf("\n");
s21_strstr_test(check2, test2);
printf("\n");
s21_strstr_test(check4, test3);
printf("\n");
s21_strstr_test(check3, test2);
#endif

return 0;
}
void s21_strlen_test(char *str, int y) {
    read_str(str);
    printf(" %d", s21_strlen(str));
    printf(" %s", s21_strlen(str) == y ? "SUCCESS" : "FAIL");
}

void s21_strcmp_test(char *str1, char *str2) {
    read_str(str1);
    printf(" ");
    read_str(str2);
    printf(" ");
    printf(" %s", s21_strcmp(str1, str2) == 0 ? "SUCCESS" : "FAIL");
}

void s21_strcpy_test(char *str1, char *str2) {
    read_str(str1);
    printf(" ");
    read_str(str2);
    printf(" ");
    char* res = s21_strcpy(str1, str2);
    printf("%s %s", res, s21_strcpy(res, str2) ? "SUCCESS" : "FAIL");
}

void s21_strcat_test(char *str1, char *str2) {
    read_str(str1);
    printf(" ");
    read_str(str2);
    printf(" ");
    int str1len = s21_strlen(str1);
    int str2len = s21_strlen(str2);
    char* res = s21_strcat(str1, str2);
    printf(" %s %s", res, str1len + str2len == s21_strlen(res) ? "SUCCESS" : "FAIL");
}

void s21_strchr_test(char *str, char ch, int x) {
    read_str(str);
    printf(" ");
    printf("%c", ch);
    printf(" ");
    printf("%ld %s", s21_strchr(str, ch)-str, s21_strchr(str, ch)-str == x ? "SUCCESS" : "FAIL");
}

void s21_strstr_test(char *str, char* substr) {
    read_str(str);
    printf(" ");
    read_str(substr);
    printf(" ");
    printf("%s %s", s21_strstr(str, substr), s21_strstr(str, substr)-str ? "SUCCESS" : "FAIL");
}
