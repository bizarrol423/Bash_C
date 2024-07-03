all : clean_grep s_grep cpplint cppcheck

s_grep : clean_grep 
	@gcc -Wextra -Wall -Werror -o s_grep  s_grep.c s_grep.h

cppcheck:
	@cppcheck *.c *.h

clean_grep:
	@rm -rf s_grep

clean : 
	@rm -Rf *.out
	@rm -Rf *.dSYM
	@rm -rf test1.txt test2.txt 
	@rm -rf s_test_grep
	@rm -rf s_grep

val:
	valgrind --leak-check=yes ./s_grep -e "[0-9]" 1.txt
	valgrind --leak-check=yes ./s_grep -n species 2.txt 1.txt

cpplint:
	clang-format -i *.c *.h
	clang-format -n *.c *.h

clean_test_grep:
	@rm -rf s_test_grep

test: s_grep
	grep mimicry 1.txt > test1.txt && ./s_grep mimicry 1.txt > test2.txt && diff test1.txt test2.txt
	grep -e "[0-9]" 1.txt > test1.txt && ./s_grep -e "[0-9]" 1.txt > test2.txt && diff test1.txt test2.txt
	grep -e species 2.txt 1.txt > test1.txt && ./s_grep -e species 2.txt 1.txt > test2.txt && diff test1.txt test2.txt
	grep -i MIMICRY 2.txt > test1.txt && ./s_grep -i MIMICRY 2.txt > test2.txt && diff test1.txt test2.txt
	grep -i SPECIES 2.txt 1.txt > test1.txt && ./s_grep -i SPECIES 2.txt 1.txt > test2.txt && diff test1.txt test2.txt
	grep -v mimicry 2.txt > test1.txt && ./s_grep -v mimicry 2.txt > test2.txt && diff test1.txt test2.txt
	grep -n species 2.txt > test1.txt && ./s_grep -n species 2.txt > test2.txt && diff test1.txt test2.txt
	grep -n species 2.txt 1.txt > test1.txt && ./s_grep -n species 2.txt 1.txt > test2.txt && diff test1.txt test2.txt
	grep -l species 2.txt > test1.txt && ./s_grep -l species 2.txt > test2.txt && diff test1.txt test2.txt
	grep -l species 2.txt 1.txt > test1.txt && ./s_grep -l species 2.txt 1.txt > test2.txt && diff test1.txt test2.txt
	grep -c species 2.txt > test1.txt && ./s_grep -c species 2.txt > test2.txt && diff test1.txt test2.txt
	grep -c species 2.txt 1.txt > test1.txt && ./s_grep -c species 2.txt 1.txt > test2.txt && diff test1.txt test2.txt
	grep -n species 2.txt > test1.txt && ./s_grep -n species 2.txt > test2.txt && diff test1.txt test2.txt
	grep -n species 2.txt 1.txt > test1.txt && ./s_grep -n species 2.txt 1.txt > test2.txt && diff test1.txt test2.txt
	grep -h species 2.txt > test1.txt && ./s_grep -h species 2.txt > test2.txt && diff test1.txt test2.txt
	grep -h species 2.txt 1.txt > test1.txt && ./s_grep -h species 2.txt 1.txt > test2.txt && diff test1.txt test2.txt
	grep -o species 2.txt 1.txt > test1.txt && ./s_grep -o species 2.txt 1.txt > test2.txt && diff test1.txt test2.txt
	grep -oh species 2.txt 1.txt > test1.txt && ./s_grep -oh species 2.txt 1.txt > test2.txt && diff test1.txt test2.txt
	grep -ol species 2.txt 1.txt > test1.txt && ./s_grep -ol species 2.txt 1.txt > test2.txt && diff test1.txt test2.txt
	grep -il species 2.txt 1.txt > test1.txt && ./s_grep -il species 2.txt 1.txt > test2.txt && diff test1.txt test2.txt
	grep -hl species 2.txt 1.txt > test1.txt && ./s_grep -hl species 2.txt 1.txt > test2.txt && diff test1.txt test2.txt
	grep -hv species 2.txt 1.txt > test1.txt && ./s_grep -hv species 2.txt 1.txt > test2.txt && diff test1.txt test2.txt
	grep -cv species 2.txt 1.txt > test1.txt && ./s_grep -cv species 2.txt 1.txt > test2.txt && diff test1.txt test2.txt
	grep -ch species 2.txt 1.txt > test1.txt && ./s_grep -ch species 2.txt 1.txt > test2.txt && diff test1.txt test2.txt