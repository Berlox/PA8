all: main

main: FinalForm.o fileops.o iterative.o
	gcc FinalForm.o fileops.o iterative.o -lm -o testf

RMV: recMaxVal.c fileops.o
	gcc recMaxVal.c fileops.o -o testf
FinalForm.o: FinalForm.c
	gcc -c FinalForm.c

fileops.o: fileops.c
	gcc -c fileops.c

iterative.o: iterative.c
	gcc -c iterative.c

debug: fileops.c FinalForm.c iterative.c
	gcc -g FinalForm.c fileops.c iterative.c -lm -o debug
	gdb debug

clean:
	rm *.o testf debug
