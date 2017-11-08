default: prog

dynArray.o: skipList.c skipList.h
	gcc -Wall -ansi -c skipList.c

prog: skipList.o
	gcc -Wall -ansi -o prog skipList.c

clean:
	rm *.o
