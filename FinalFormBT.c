/*
This will be the final generation of the code, where it seeks the max value from the array using recursion while saving with dynamic programming
and tracking which is which.
Students: Christian Dunn Dejan Mandic.
CSE 222 PA8
*/

#include "fileops.h"

struct Path { //a struct to hold the path, stored in an array of length based on how long the length is and a integer of how long the actual path is.
  int maxVal;
  int *list;
  int size; //how long the path is
  int found; //flag to see if we actually have found it yet.
};

typedef struct Path path;

int max(int a, int b) {return (a > b)? a:b;}
int maxValue(inv_val* inv, int length); //returns the maxValue from the inventory.

//global value of the paths.
path *Found; //global array

int calls;
int main(int argc, char const *argv[]) {
  calls = 0;
  if (argc != 2) {
    printf("Usage: %s length\n", argv[0]);
    return 0;
  }
  int length = atoi(argv[1]);
  Found = (path *) malloc (sizeof(path) * length + 1); //plus one so we dont have to call -1 everywhere else.
  int i;
  for (i = 0; i < length +1; i++) {
    Found[i].found = 0;
  }
  inv_val *inv;
  inv = initinv();
  //fill the memory
  if (fetchData("inventory.txt", inv) != 1)
  {
    printf("error\n");
    exit(1);
  }
  int value = maxValue(inv, length);
  printf("Max value for length %d is %d %d\n", length, value, calls);

  freeinv(inv);
  return 0;
}


int maxValue(inv_val *inv, int length) {
  calls++;
  if (length <= 0) {
    //Base case
    return 0;
  }
  //if (length == 1) {
    //return inv->val[1];
  //}
  if (Found[length].found == 0) {
    int maxv = 0;
    int maxlength;
    int temp; //so we dnt have to calulate everything again.
    int i;
    for (i = 1; i <= length; i++) {
      maxv = max(maxv, (inv->val[i] + maxValue(inv, length - i)));
      if (i > inv->size) {
        printf("Invalid Inventory File\n");
        exit(0); //if the walue isnt in the exit.

      }
    }
    Found[length].found = 1;
    Found[length].maxVal = maxv;
    return maxv;
  }
  else return Found[length].maxVal;
}
