#include "fileops.h"

int main(int argc, char const *argv[]) {
  inv_val *inv;
  inv = initinv(inv);
  switch (fetchData("inventory.txt", inv)) {
    case 1:
      break;
    case 0:
      printf("Failed\n");
      return 0;
    case -1:
      printf("File open Fail\n");
      return -1;
    case -2:
      printf("Bad Memory\n");
      return -2;
    case -3:
      printf("Bad format\n");
      return -3;
  }
  int i;
  for (i = 1; i <= inv->size; i++) {
    printf("%d units long is worth %d monies\n", i, inv->val[i]);
  }
  return 0;
}
