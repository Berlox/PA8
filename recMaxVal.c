/*
This will be the second generation of the code, where it seeks the max value from the array using recursion without saving which is which.
Students: Christian Dunn Dejan Mandic.
CSE 222 PA8
*/

#include "fileops.h"
int max(int a, int b) {return (a > b)? a:b;}
int maxValue(inv_val* inv, int length); //returns the maxValue from the inventory.
int calls;
int main(int argc, char const *argv[]) {
  calls = 0;
  if (argc != 2) {
    printf("Usage: %s length\n", argv[0]);
    return 0;
  }
  int length = atoi(argv[1]);
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
  return maxv;
}
