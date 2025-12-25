#include <stdio.h>

int main() {

  int LA[] = {1, 3, 5, 7, 8};
  int item = 5, n = 5;
  int i = 0, j = 0;
  printf("the original array elements are : \n");

  for (i = 0; i < n; i++) {
    printf("la[%d] = %d \n", i, LA[i]);
  }

  while (j < n) {

    if (LA[j] == item) {
      break;
    }

    j = j + 1;
  }

  printf("Found elemnt %d at position %d \n", i, j + 1);

  return 0;
}
