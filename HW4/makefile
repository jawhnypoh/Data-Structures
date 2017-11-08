default: prog

dynArray.o: dynArray.c dynArray.h type.h
	gcc -Wall -ansi -c dynArray.c

toDoList.o: toDoList.c toDoList.h type.h
	gcc -Wall -ansi -c toDoList.c

prog: dynArray.o toDoList.o main.c
	gcc -Wall -ansi -o prog dynArray.o toDoList.o main.c

clean:
	rm dynArray.o
	rm toDoList.o

cleanall: clean
	rm prog
