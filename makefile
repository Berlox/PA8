all: main

main: testmain.o fileops.o
	gcc -o  testf testmain.o fileops.o

testmain.o: testmain.c
	gcc -c testmain.c

fileops.o: fileops.c
	gcc -c fileops.c

debug:
	gcc -g testmain.c fileops.c -o debug

clean:
	rm *.o testf debug
