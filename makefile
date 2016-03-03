all: main

main: recMaxVal.o fileops.o
	gcc -o  testf recMaxVal.o fileops.o

recMaxVal.o: recMaxVal.c
	gcc -c recMaxVal.c

fileops.o: fileops.c
	gcc -c fileops.c

debug: recMaxVal.c
	gcc -g recMaxVal.c fileops.c -o debug

clean:
	rm *.o testf debug
