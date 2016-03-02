//The file to contain operations for opening file and setting values.


void initinv(inv_val *inv) {
  //this will initialize memory and values for the inv array
  inv->size = 0;
  inv->val = (int *) malloc(SIZE*sizeof(int));
  inv->maxSize = SIZE;
}


int fetchData(const char *fn, inv_val* inv) {
  //sets the inventoryValues from a file given filename
  //returns 1 on success, 0 on fail, -1 on fail due to lack of file. -2 if memfail.
  FILE *fp = fopen(fn, 'r'); //open for reading
  if (fp == NULL) return -1; //if error opening file, return -1
  char buffer[BUFFSIZE];
  int x,y; //2 variables, 1 will be index, other will be value for index.
  while (fgets(buffer, BUFFSIZE, fp) != NULL) {
    //read entire file line by line, add it to the array, if array is too small allocate more memory
    if (sscanf(buffer, "%d %d", &x, &y) != 2) //we need to parse 2 values for this to work
    {
      while (inv->maxSize <= x) {
        //if the index is less than the size of the array, we need a bigger array
        inv->maxSize += STEPSIZE;
        inv->val = (int *) realloc(inv->maxSize * sizeof(int));
        if (inv->val == NULL) return -2;
      }
      inv->val[x] = y; //actually add it to the array;
      inv->size++;
    }
    else return -1 //bad file if not 2 values.
  }
  return 1; //if it made it this far, it should be good.
}
