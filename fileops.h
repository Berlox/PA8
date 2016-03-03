//This is a header file to mostly just for functions and structs to retrieve the values of the inventory.txt
//CSE 222
//Christian Dunn Dejan Mandic ft. "The other Kid" (sorry, never learned your name. I'll update it later.) apparently whose name is Ben

#include <stdlib.h>
#include <stdio.h>
#define SIZE 10
#define STEPSIZE 10
#define BUFFSIZE 100

struct InventoryValues {
  int *val; //going to be a dynamically allocated array
  int size; //current size of the array
  int maxSize; //maximum that can currently be stored in the array
} typedef inv_val;

inv_val *initinv(); //allocates memory for the array and sets size to zero
int fetchData(const char *fn, inv_val *inv); //sets the inventory values from a file given in fn closes the file when it's done
//above function returns 1 on sucess, 0 on fail, -1 on fail due to a missing file. -2 if memfail
void freeinv(inv_val *inv); //frees the memory associated with inv
