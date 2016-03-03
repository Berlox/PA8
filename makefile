all: main

main: recMaxVal.o fileops.o
	gcc recMaxVal.o fileops.o -o testf

recMaxVal.o: recMaxVal.c
	gcc -c recMaxVal.c

fileops.o: fileops.c
	gcc -c fileops.c

debug:
	gcc -g recMaxVal.c fileops.c -o debug

clean:
	rm *.o testf debug
