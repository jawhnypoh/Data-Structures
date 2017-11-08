default: prog

dynArray.o: dynArray.c dynArray.h
	gcc -Wall -ansi -c dynArray.c

prog: dynArray.o
	gcc -Wall -ansi -o prog dynArray.o stackapp.c

clean:
	rm dynArray.o

cleanall: clean
	rm *.o
