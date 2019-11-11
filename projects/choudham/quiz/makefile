#In command line enter 'make' first and press 'enter'
#Then in command line enter 'make run' 

default: prog

prog:
	gcc -Wall -std=c99 -o prog testme.c -coverage -fpic -lm

run:
	./prog
		
clean:
	rm prog

cleanall: 
	rm prog 
