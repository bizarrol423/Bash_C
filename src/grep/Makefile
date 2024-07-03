all : clean_grep s21_grep cpplint cppcheck

s21_grep : clean_grep 
	@gcc -Wextra -Wall -Werror -o s21_grep  s21_grep.c s21_grep.h

cppcheck:
	@cppcheck *.c *.h

clean_grep:
	@rm -rf s21_grep

clean : 
	@rm -Rf *.out
	@rm -Rf *.dSYM
	@rm -rf test1.txt test2.txt 
	@rm -rf s21_test_grep
	@rm -rf s21_grep

val:
	valgrind --leak-check=yes ./s21_grep -e "[0-9]" 1.txt
	valgrind --leak-check=yes ./s21_grep -n species 2.txt 1.txt

cpplint:
	clang-format -i *.c *.h
	clang-format -n *.c *.h

clean_test_grep:
	@rm -rf s21_test_grep

test: s21_grep
	grep mimicry 1.txt > test1.txt && ./s21_grep mimicry 1.txt > test2.txt && diff test1.txt test2.txt
	grep -e "[0-9]" 1.txt > test1.txt && ./s21_grep -e "[0-9]" 1.txt > test2.txt && diff test1.txt test2.txt
	grep -e species 2.txt 1.txt > test1.txt && ./s21_grep -e species 2.txt 1.txt > test2.txt && diff test1.txt test2.txt
	grep -i MIMICRY 2.txt > test1.txt && ./s21_grep -i MIMICRY 2.txt > test2.txt && diff test1.txt test2.txt
	grep -i SPECIES 2.txt 1.txt > test1.txt && ./s21_grep -i SPECIES 2.txt 1.txt > test2.txt && diff test1.txt test2.txt
	grep -v mimicry 2.txt > test1.txt && ./s21_grep -v mimicry 2.txt > test2.txt && diff test1.txt test2.txt
	grep -n species 2.txt > test1.txt && ./s21_grep -n species 2.txt > test2.txt && diff test1.txt test2.txt
	grep -n species 2.txt 1.txt > test1.txt && ./s21_grep -n species 2.txt 1.txt > test2.txt && diff test1.txt test2.txt
	grep -l species 2.txt > test1.txt && ./s21_grep -l species 2.txt > test2.txt && diff test1.txt test2.txt
	grep -l species 2.txt 1.txt > test1.txt && ./s21_grep -l species 2.txt 1.txt > test2.txt && diff test1.txt test2.txt
	grep -c species 2.txt > test1.txt && ./s21_grep -c species 2.txt > test2.txt && diff test1.txt test2.txt
	grep -c species 2.txt 1.txt > test1.txt && ./s21_grep -c species 2.txt 1.txt > test2.txt && diff test1.txt test2.txt
	grep -n species 2.txt > test1.txt && ./s21_grep -n species 2.txt > test2.txt && diff test1.txt test2.txt
	grep -n species 2.txt 1.txt > test1.txt && ./s21_grep -n species 2.txt 1.txt > test2.txt && diff test1.txt test2.txt
	grep -h species 2.txt > test1.txt && ./s21_grep -h species 2.txt > test2.txt && diff test1.txt test2.txt
	grep -h species 2.txt 1.txt > test1.txt && ./s21_grep -h species 2.txt 1.txt > test2.txt && diff test1.txt test2.txt
	grep -o species 2.txt 1.txt > test1.txt && ./s21_grep -o species 2.txt 1.txt > test2.txt && diff test1.txt test2.txt
	grep -oh species 2.txt 1.txt > test1.txt && ./s21_grep -oh species 2.txt 1.txt > test2.txt && diff test1.txt test2.txt
	grep -ol species 2.txt 1.txt > test1.txt && ./s21_grep -ol species 2.txt 1.txt > test2.txt && diff test1.txt test2.txt
	grep -il species 2.txt 1.txt > test1.txt && ./s21_grep -il species 2.txt 1.txt > test2.txt && diff test1.txt test2.txt
	grep -hl species 2.txt 1.txt > test1.txt && ./s21_grep -hl species 2.txt 1.txt > test2.txt && diff test1.txt test2.txt
	grep -hv species 2.txt 1.txt > test1.txt && ./s21_grep -hv species 2.txt 1.txt > test2.txt && diff test1.txt test2.txt
	grep -cv species 2.txt 1.txt > test1.txt && ./s21_grep -cv species 2.txt 1.txt > test2.txt && diff test1.txt test2.txt
	grep -ch species 2.txt 1.txt > test1.txt && ./s21_grep -ch species 2.txt 1.txt > test2.txt && diff test1.txt test2.txt