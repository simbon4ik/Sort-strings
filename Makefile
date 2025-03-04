all: prog.o library.o input.o mystring.o
	gcc prog.o library.o input.o mystring.o -o prog -g

prog.o: prog.c 
	gcc -c prog.c 

library.o: library.c 
	gcc -c library.c 

input.o: input.c 
	gcc -c input.c 

mystring.o: mystring.c 
	gcc -c mystring.c 

clean:
	rm -f *.o
	
