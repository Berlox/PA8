/*
This will be the second generation of the code, where it seeks the max value from the array using recursion without saving which is which.
Students: Christian Dunn Dejan Mandic.
CSE 222 PA8
*/

#include "fileops.h"


int maxValue(inv_val* inv, int length); //returns the maxValue from the inventory.

int main(int argc, char const *argv[]) {
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
  int value = maxValue(inv, 10);
  printf("Max value for length %d is %d\n", length, value);

  return 0;
}
int maxValue(inv_val *inv, int length) {
  if (length <= 0) {
    //Base case
    return 0;
  }
  int max = 0;
  int temp; //so we dnt have to calulate everything again.
  int i;
  for (i = 1; i <= inv->size; i++) {
    temp = inv->val[i] + maxValue(inv, length - i);
    if ( temp > max) {
      max = temp;
    }
  }
  return max;
}
