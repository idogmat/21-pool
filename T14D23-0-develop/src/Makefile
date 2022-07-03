.PHONY: all clean rebuild
 
CFLAGS = -Wall -Werror -Wextra
PTHB = ../build/

all: state_sort state_search clear_state

state_sort: state_sort.c binary_files_common_functions.c state_sort.h binary_files_common_functions.h
	gcc $(CFLAGS) state_sort.c binary_files_common_functions.c -c
	gcc state_sort.o binary_files_common_functions.o -o $(PTHB)Quest_1

state_search: state_search.c binary_files_common_functions.c state_search.h binary_files_common_functions.h
	gcc $(CFLAGS) state_search.c binary_files_common_functions.c -c
	gcc state_search.o binary_files_common_functions.o -o $(PTHB)Quest_2

clear_state: clear_state.c binary_files_common_functions.c clear_state.h binary_files_common_functions.h
	gcc $(CFLAGS) clear_state.c binary_files_common_functions.c -c
	gcc clear_state.o binary_files_common_functions.o -o $(PTHB)Quest_3

pyt: 
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extensions=c *.c
	python3 ../materials/linters/cpplint.py --extensions=h *.h
	rm -rf CPPLINT.cfg


clean:
	rm -rf *.o *.a *.so $(PTHB)Quest*
 
 
rebuild:
	$(MAKE) clean
	$(MAKE) all
