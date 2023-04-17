#include <stdio.h>
#include <stdlib.h>

void makeSquare (int square[11][11], int N);
void printSquare ();

int main (int argc, char *argv[]) {

  /* integers */
  int row, col;
  int n = atoi(argv[1]);
  int magicSquare[11][11];

  printf("The number of rows and columns will be %d\n", n);
  makeSquare(magicSquare, n);
  printSquare(magicSquare, n);

  return 0;
}

void makeSquare (int square[11][11], int N) {
  int row, col, i;
  row = 0;
  col = (N - 1) / 2;

  for (i = 1; i <= N * N; i++) {
    square[row][col] = i;
    row--;
    if(row < 0) {
      row = N - 1;
    }
    col++;
    if(col >= N) {
      col = 0;
    }
    if (square[row][col] > 0) {
      row += 2;
      if(row >= N) {
        row = row - N;
      }
      col--;
      if (col < 0) {
        col = N - 1;
      }
    } /* end of if-loop */
  } /* end of for-loop */
} /* end of makeSquare function */

void printSquare (int square[][11], int N) {
  int i, j, row, col;
  row = 0;
  col = 0;
  for(i = 0; i < N; i++) {
    for (j =0; j < N; j++) {
      printf("%4d", square[i][j]);
    } /* end of for-loop */
    printf("\n");
  } /* end of for-loop */
} /* end of printSquare function */
