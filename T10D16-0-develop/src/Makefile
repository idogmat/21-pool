CC=gcc
FLAG=-Wall -Wextra -Werror

all: 
	gcc $(FLAG) -Wall -Wextra -Werror -DSTRLEN s21_string_test.c s21_string.c -o ../build/Quest_1
	gcc $(FLAG) -DSTRCMP s21_string_test.c s21_string.c -o ../build/Quest_2
	gcc $(FLAG) -DSTRCPY s21_string_test.c s21_string.c -o ../build/Quest_3
	gcc $(FLAG) -DSTRCAT s21_string_test.c s21_string.c -o ../build/Quest_4
	gcc $(FLAG) -DSTRCHR s21_string_test.c s21_string.c -o ../build/Quest_5
	gcc $(FLAG) -DSTRSTR s21_string_test.c s21_string.c -o ../build/Quest_6
clean:
	rm ../build/Q*

strlen_tests:
	gcc -DSTRLEN s21_string_test.c s21_string.c -o ../build/Quest_1
strcmp_tests:
	gcc -DSTRCMP s21_string_test.c s21_string.c -o ../build/Quest_2
strcpy_tests:
	gcc -DSTRCPY s21_string_test.c s21_string.c -o ../build/Quest_3
strcat_tests:
	gcc -DSTRCAT s21_string_test.c s21_string.c -o ../build/Quest_4
strchr_tests:
	gcc -DSTRCHR s21_string_test.c s21_string.c -o ../build/Quest_5
strstr_tests:
	gcc -DSTRSTR s21_string_test.c s21_string.c -o ../build/Quest_6
rebuild:
	gcc -DSTRLEN s21_string_test.c s21_string.c -o ../build/Quest_1
	gcc -DSTRCMP s21_string_test.c s21_string.c -o ../build/Quest_2
	gcc -DSTRCPY s21_string_test.c s21_string.c -o ../build/Quest_3
	gcc -DSTRCAT s21_string_test.c s21_string.c -o ../build/Quest_4
	gcc -DSTRCHR s21_string_test.c s21_string.c -o ../build/Quest_5
	gcc -DSTRSTR s21_string_test.c s21_string.c -o ../build/Quest_6