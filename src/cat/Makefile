OS=$(shell uname -s)
ifeq ($(OS), Linux)
 N = --number
 B = --number-nonblank
 S = --squeeze-blank
else ifeq ($(OS) , Darwin)
 N = -n
 B = -b
 S = -s
endif
all : clean_cat s21_cat cpplint cppcheck
s21_cat : clean_cat 
	@gcc  -o s21_cat  s21_cat.c s21_cat.h


clean_cat:
	@rm -rf s21_cat

cppcheck:
	@cppcheck *.c *.h
clean : 
	@rm -Rf *.out
	@rm -Rf *.dSYM
	@rm -rf test1.txt test2.txt 
	@rm -rf s21_test_cat
	@rm -rf s21_cat

cpplint:
	clang-format -i *.c *.h
	clang-format -n *.c *.h

val:
	valgrind --leak-check=yes ./s21_cat -te 2.txt 1.txt
	valgrind --leak-check=yes ./s21_cat -ne bytes.txt
	valgrind --leak-check=yes ./s21_cat -s bytes.txt
	valgrind --leak-check=yes ./s21_cat bytes.txt


test: s21_cat 
	rm -rf test1.txt test2.txt   
	./s21_cat $(B) 1.txt > test1.txt && cat $(B) 1.txt > test2.txt && diff test1.txt test2.txt
	./s21_cat -e 1.txt bytes.txt > test1.txt && cat -e 1.txt bytes.txt > test2.txt && diff test1.txt test2.txt
	./s21_cat $(N) bytes.txt > test1.txt && cat $(N) bytes.txt > test2.txt && diff test1.txt test2.txt
	./s21_cat $(S) bytes.txt > test1.txt && cat $(S) bytes.txt > test2.txt && diff test1.txt test2.txt
	./s21_cat $(B) bytes.txt > test1.txt && cat $(B) bytes.txt > test2.txt && diff test1.txt test2.txt
	./s21_cat -e 2.txt > test1.txt && cat -e 2.txt > test2.txt && diff test1.txt test2.txt
	./s21_cat $(N) 2.txt > test1.txt && cat $(N) 2.txt > test2.txt && diff test1.txt test2.txt
	./s21_cat $(S) 2.txt > test1.txt && cat $(S) 2.txt > test2.txt && diff test1.txt test2.txt
	cat -t bytes.txt > test1.txt && ./s21_cat -t bytes.txt > test2.txt && diff test1.txt test2.txt
	cat -e bytes.txt > test1.txt && ./s21_cat -e bytes.txt > test2.txt && diff test1.txt test2.txt
	cat bytes.txt > test1.txt && ./s21_cat bytes.txt > test2.txt && diff test1.txt test2.txt

