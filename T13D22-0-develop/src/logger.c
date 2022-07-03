// "Copyright [2022] <Jeseniam>"
#include <stdio.h>
#include <time.h>
void read_str(char *str);
void log_init(char *file, char* str, int flag) {
struct tm *ptr;
time_t It;
It = time(NULL);
ptr = localtime(&It);
FILE*log;
if ((log = fopen("cipher.log", "r")) == NULL) {
    fclose(log);
    log = fopen("cipher.log", "w");
    fprintf(log, "%s\t%s\tfile_name:%s\tstatus:%s",
    asctime(ptr), "INFO: ", file, flag == 1 ? str : "file empty");
    fclose(log);
} else {
    log = fopen("cipher.log", "a");
    fprintf(log, "\n%s\t%s\tfile_name:%s\tstatus:%s",
    asctime(ptr), "INFO: ", file, flag == 1 ? str : "file empty");
    fclose(log);
}
}
void read_str(char *str) {
    int i = 0;
    while (str[i] != '\0') {
    printf("%c", str[i]);
    ++i;
    }
}
void logcat(char *file, char* str, int flag) {
struct tm *ptr;
time_t It;
It = time(NULL);
ptr = localtime(&It);
FILE*log;
if((log=fopen("cipher.log", "r")) == NULL) {
    fclose(log);
    log = fopen("cipher.log", "w");
    fprintf(log, "%s\t%s\tfile_name: %s\tadd_text: %s",
    asctime(ptr), "INFO: ", file, flag == 1 ? str : "file empty");
    fclose(log);
} else {
    log = fopen("cipher.log", "a");
    fprintf(log, "\n%s\t%s\tfile_name: %s\tadd_text: %s",
    asctime(ptr), "INFO: ", file, flag == 1 ? str : "file empty");
    fclose(log);
}
}

void log_close(char *file) {
struct tm *ptr;
time_t It;
It = time(NULL);
ptr = localtime(&It);
FILE*log;

if((log=fopen("cipher.log", "r")) == NULL) {
    fclose(log);
    log = fopen("cipher.log", "w");
    fprintf(log, "%s\t %s\t%s\t %s",
    asctime(ptr), "INFO: ", file, "was closed");
    fclose(log);
} else {
    log = fopen("cipher.log", "a");
    fprintf(log, "\n%s\t %s\t%s\t %s",
    asctime(ptr), "INFO: ", file, "was closed");
    fclose(log);
}
}
void Cezar_joke() {
struct tm *ptr;
time_t It;
It = time(NULL);
ptr = localtime(&It);
FILE*log;

if((log=fopen("cipher.log", "r")) == NULL) {
    fclose(log);
    log = fopen("cipher.log", "w");
    fprintf(log, "%s\t %s",
    asctime(ptr), "WARNING: Cezar did business in the AI's folder");
    fclose(log);
} else {
    log = fopen("cipher.log", "a");
    fprintf(log, "\n%s\t %s",
    asctime(ptr), "WARNING: Cezar did business in the AI's folder");
    fclose(log);
}
}
