#This makefile is for 
cc = "gcc"
objects = IntSort.o prepareFun.o

main:$(objects)
	gcc -o main $(objects) main.c
IntSort.o:prepareFun.h
	gcc -c IntSort.c
prepareFun.o:
	gcc -c prepareFun.c
.PHONY:clean

clean:
	rm -f *.o main