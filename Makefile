all:
				gcc -std=c99 -Wall -Werror main.c node.c tree.c
				valgrind ./a.out
