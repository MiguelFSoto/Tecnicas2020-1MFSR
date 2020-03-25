all: Program

Program: Functions Main
	gcc main.o users.o -o final.exe	

Functions: users.c users.h
	gcc -c users.c

Main: main.c users.c
	gcc -c main.c