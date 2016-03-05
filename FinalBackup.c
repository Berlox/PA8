/*
This will be the final generation of the code, where it seeks the max value from the array using recursion while saving with dynamic programming
and tracking which is which.
Students: Christian Dunn Dejan Mandic.
CSE 222 PA8
*/

#include "fileops.h"
#include <string.h> //for memcpy

struct Path { //a struct to hold the path, stored in an array of length based on how long the length is and a integer of how long the actual path is.
  int maxVal;
  int *list;
  int size; //how long the list is
  int found; //flag to see if we actually have found it yet.
};

typedef struct Path path;

int max(int a, int b) {return (a > b)? a:b;}
int maxValue(inv_val* inv, int length); //returns the maxValue from the inventory.

//global value of the paths.
path *Found; //global array
int count; //to make sure its doing shit right.
int main(int argc, char const *argv[]) {
if (argc != 2) {
    printf("Usage: %s length\n", argv[0]);
    return 0;
  }
  int length = atoi(argv[1]);
  Found = (path *) malloc (sizeof(path ) * (length + 1)); //we do +1 so we can have an empty 0 element and not do -1 everywhere else.
  int i;
  //initialize everything in the array to NULL
  for (i = 0; i < length + 1; i++) {
    Found[i].found = 0; //set them to not be Found
    //Found[i].list = NULL;
  }
  //base case for the found. This way makes it easier to treat FOund recursively.
  Found[0].found = 1; //set it to think it's been Found
  Found[0].size = 0; //no elements
  Found[0].maxVal = 0;
  //Found[0].list = NULL; //Set the list to nothing, since length is zero, it should never be called.
  count = 0; //tracker to see how many calls ar emade
  inv_val *inv;
  //fill the memory
  inv = initinv();
  if (fetchData("inventory.txt", inv) != 1) {
    printf("error\n");
    exit(1);
  }
  int value = maxValue(inv, length);
  printf("Max value for length %d is %d %d\n", length, value, count);
  //for (i = 0; i < Found[length].size; i++) {
    //print array
    //printf("%d ", Found[length].list[i]);
  //}
  return 0;
}


int maxValue(inv_val *inv, int length) {
  count++;
  if (length <= 0) {
    //Base case
    return 0;
  }
  //if (length == 1) {
    //return inv->val[1];
  //}
  int maxv = 0;
  //int maxlength = 0;
  int temp; //so we dnt have to calulate everything again.
  int i;
  if (Found[length].found ==  0) {
    //if it hasnt been found before.
    for (i = 1; i <= length; i++) {
      temp = maxValue(inv, length - i);
      if (temp > maxv)
      {
        //if the new value is greatest. set maxv and maxlength
        maxv = temp; //set the max value here
        //maxlength = i; //set the max values length here
      }
      if (i > inv->size) {
        printf("Invalid Inventory File\n");
        exit(0); //if the walue isnt in the exit.

      }
    }
    //save all the shit.
    Found[length].maxVal = maxv; //store the maxVal for later use.
    Found[length].found = 1; //let the masses know the value has been searched for before.
    /*if (Found[length].list == NULL) Found[length].list = (int *) malloc (sizeof(int) * length+1); //set the size of path to be equal to the length, which is the max size.
    //if (((length-maxlength) > 0) && (Found[length-maxlength].size != 0)) {
      //base case where the next one down is 0, so it's length is 0. make sure we dont seg fault.
      memcpy(Found[length].list, Found[length-maxlength].list, (Found[length-maxlength].size * sizeof(int))); //copy the contents of the next length down over.
    //} //this wasnt actually the problem.
    Found[length].size = Found[length-maxlength].size + 1; //one longer than the last one down.
    Found[length].list[Found[length].size-1] = maxlength; */
    return maxv;
  }
  else return Found[length].maxVal;
}
