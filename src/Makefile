.SILENT:

CC = gcc -Wall -Werror -Wextra -std=c11 
GCOVFLAGS = -fprofile-arcs -ftest-coverage
LIBS = -lcheck 
PROJECTNAME = s21_math

OS := $(shell uname -s)
ifeq ($(OS), Darwin)
	CC += -D OS_MAC
	TEST_FLAGS = $(LIBS)
endif
ifeq ($(OS), Linux)
	CC += -D OS_LINUX
	TEST_FLAGS = -lpthread $(LIBS) -pthread -lrt -lm -lsubunit
endif

all: $(PROJECTNAME).a

$(PROJECTNAME).a: clean
	${CC} -c s21_*.c
	ar rc $(PROJECTNAME).a s21_*.o
	ranlib $(PROJECTNAME).a

test: $(PROJECTNAME).a
	${CC} tests.c $(PROJECTNAME).a $(TEST_FLAGS) -o test
	./test

gcov_report: clean
	@${CC} $(GCOVFLAGS) s21_*.c tests.c $(TEST_FLAGS) -o test_report $(LIBS)
	@./test_report
	@lcov -t test_report -o test.info -c -d .
	@genhtml -o report test.info
	@open ./report/index-sort-f.html

rebuild: clean all 

clean:
	-rm -rf $(PROJECTNAME)
	-rm -rf *.gcda
	-rm -rf *.gcno
	-rm -rf *.a
	-rm -rf *.o
	-rm -rf test
	-rm -rf test_report
	-rm -rf test.info
	-rm -rf report
	clear

clang:
	clang-format --style=Google -n *.c *.h
	clang-format --style=Google -i *.c *.h

