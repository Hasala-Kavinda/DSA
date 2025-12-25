
#include <stdio.h>

int main(){

  int la[] = {1, 3, 5, 7, 8};
  int k = 3, n = 5;
  int i = 0, j = n ;
  printf("the original array elements are : \n");

  for( i = 0 ; i < n; i++)
  {
    printf("la[%d] = %d \n", i, la[i]);
  }

  j= k;
  while(j < n){
    la[j-1] = la[j];
    j = j+1;
  }

   
  n = n-1;
  printf("the array elements after deletion: \n");

  for( i = 0 ; i < n; i++)
  {
    printf("la[%d] = %d \n", i, la[i]);
  }


  return 0;
}
