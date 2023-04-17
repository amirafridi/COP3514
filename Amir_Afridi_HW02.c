/*
 Amir Afridi
 U01470999
 Homework 2
 COP 3514
 */

/* This program will ask the user to input an odd integer(N) between 3 and 11, and output a magic square with N rows and columns */
// What are magic squres? https://en.wikipedia.org/wiki/Magic_square

#include <stdio.h>

/* program functions */
int makeSquare(int[][11], int);
void printSquare(int[][11], int);
int magicSquare [11][11];

/*** Main function, to process the program ***/
int main () {
    
    int N;
    int sum;
    /* Ask the user to input an integer, and set that integer equal to N. */
    printf("\n Enter the size of the magic square (odd integer 3-11): ");
    scanf("%d", &N);
    /* If the integer is not an odd integer between 3 and 11, print Invalid Reply, and complete the program. */
    if (N < 3 || N > 11 || N % 2 != 1) {
        printf(" Invalid Input: %d \n", N);
        return 0;
    }
    
    sum=makeSquare(magicSquare,N);
    printf("\n");
    printSquare(magicSquare, N);
    /* Print the sum of all numbers in the square. */
    printf("\n Sum of Magic Numbers: %d.\n", sum);
    
    return 0;
}

/*** This function makes the magic square ***/
int makeSquare(int grid[][11], int N) {
    
    int x;
    int row;
    int column;
    int sum;
    
    /* Make the magic square N rows by N columns.  Initialize all integers in the magic square by setting them equal to 0. */
    for (row = 0; row < N; row++) {
            for(column = 0; column < N; column++) {
                magicSquare[row][column] = 0;
            }
        }
    /* Start the magic square in the middle of the first row. */
    row = 0;
    column = (N - 1) / 2;
        /* This starts the 'for loop' that will create the magic square. */
        /* This for-loop will run until the magic square is filled. */
        for (x = 1; x <= N * N; x++) {
            
            /* Put 'x' in the spot on the magic square. */
            magicSquare[row][column] = x;
            /* After a number is entered in the square, move up one row, and to the right one column. */
            /* Going outside the bounds of the magic square will wrap to the other side. 
             (ex. column = n: because there is no column = n, it will wrap around to column = 0) */
            row -= 1;
            if (row < 0) {
                row = N - 1;}
            column += 1;
            if (column >= N){
                column = 0;}

            /* If Magic Square space is occupied, move the new number below the previous number */
            if (magicSquare[row][column] > 0) {
                row = row + 2;
                if (row >= N) {
                    row = row - N;
                }
                column -= 1;
                if (column < 0) {
                    column = N - 1;
                }
            }
        }
    
            /* This for-loop will find the sum of one row of numbers in the magic square. */
            for(row = 0; row < N; row++) {
                for(column = 0, sum = 0; column < N; column++) {
                    sum += magicSquare[row][column];
                }
                /* After the program has the sum of one row of numbers, it will multiply it by the number of columns
                 to get the sum of all the numbers inside the magic squre.*/
                sum = sum * N;
                return sum;
            }
        }



/*** This function prints the magic square ***/
void printSquare(int A[][11], int size)
{
    int row, column;
    for (row = 0; row < size; row++) {
        for (column = 0; column < size; column++) {
            printf("%4d", A[row][column]);
        }
        putchar('\n');
    }
}
