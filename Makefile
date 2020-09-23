# Makefile
#
# Makefile for process implementation.
#
# Peter Kamlewechi

main: main.c
	gcc -o main main.c

main2: main2.c
	gcc -o main2 main2.c

process: process_implementation.c
	gcc -o process process_implementation.c
