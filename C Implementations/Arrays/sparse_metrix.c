
#include <stdio.h>

int main() {
  // Assume 4x5 sparce mattrix
  int sparceMatrix[4][5] = {
      {0, 0, 3, 0, 4},
      {0, 0, 5, 7, 4},
      {0, 0, 0, 0, 0},
      {0, 2, 6, 0, 0},

  };
  int size = 0;

  for (int i = 0; i < 4; i++) {

    for (int j = 0; j < 5; j++) {
      if (sparceMatrix[i][j] != 0) {
        size++;
      }
    }
  }
  int compactMateix[3][size];
  // Making of new matrix

  int k = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 5; j++) {
      if (sparceMatrix[i][j] != 0) {
        compactMateix[0][k] = i;
        compactMateix[1][k] = j;
        compactMateix[2][k] = sparceMatrix[i][j];
        k++;
      }
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < size; j++) {
      printf("%d", compactMateix[i][j]);
    }
    printf("\n");
  }

  return 0;
}
