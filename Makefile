# Makefile
#
# Makefile for process implementation.
#
# Peter Kamlewechi

process: process_implementation.c
	gcc -o process process_implementation.c
