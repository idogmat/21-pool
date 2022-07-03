#include <stdio.h>

void read_str(char *str) {
    int i = 0;
    while (str[i] != '\0') {
    printf("%c", str[i]);
    ++i;
    }
}

int s21_strlen(char *str) {
    int len = 0;
        while (str[len] != '\0') {
        ++len;
        }
    return len;
}

int s21_strcmp(char* str1, char* str2) {
    int r_v = 0;
    int i = 0;
    while (str1[i] != '\0') {
        if (str1[i] != str2[i]) {
            r_v = str1[i] -str2[i];
            break;
            }
        i++;
    }
    return r_v;
}

char* s21_strcpy(char* dest, char* src) {
    int i = 0;
    while (dest[i] != '\0') {
        dest[i] = src[i];
        i++;
        }
    dest[i] = '\0';
    return dest;
}

char* s21_strcat(char* dest, char* src) {
    int len = s21_strlen(dest);
    int i = 0;
      while (src[i] != '\0') {
      dest[len] = src[i];
      len++;
      i++;
    }
    dest[len] = '\0';
    return dest;
}

char* s21_strchr(char* dest, char ch) {
    char * p = NULL;
    if (*dest != '\0') {
        int flag = 0;
        while (*dest != '\0') {
            if (flag == 0) {
                if (*dest == ch) {
                    flag = 1;
                    p = dest;
                }
            }
            dest++;
        }
    }
    return p;
}

char* s21_strstr(char* dest, char* src) {
    char * src_ptr = NULL, * dest_ptr = NULL;
    if (dest == NULL || src == NULL) {
        return NULL;
    }
    while (*dest) {
        if (*dest == *src) {
            int trigger_out = 1;
            src_ptr = src;
            dest_ptr = dest;
            while (*src_ptr && *dest_ptr) {
                trigger_out = trigger_out && (*src_ptr == *dest_ptr);
                if (trigger_out) return dest;
            }
        }
        ++dest;
    }
    return NULL;
}
