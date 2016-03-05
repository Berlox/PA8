all: main

main: FinalForm.o fileops.o
	gcc FinalForm.o fileops.o -o testf

FinalForm.o: FinalForm.c
	gcc -c FinalForm.c

fileops.o: fileops.c
	gcc -c fileops.c

debug: fileops.c FinalForm.c
	gcc -g FinalForm.c fileops.c -o debug
	gdb debug

clean:
	rm *.o testf debug
