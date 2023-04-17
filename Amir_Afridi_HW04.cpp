/*
 Amir Afridi
 U01470999
 Homework 4
 COP 3514
 */

#include <stdio.h>

/* Define constants */
#define NUM_ROWS 3
#define NUM_COLS 2

/* functions used in the program */
void printTriangle (int points[NUM_ROWS][NUM_COLS]);
void rotateTriangle (int original[NUM_ROWS][NUM_COLS], int rotated[NUM_ROWS][NUM_COLS]);
int reflectTriangle (char reflectAxis, int original[NUM_ROWS][NUM_COLS], int reflected[NUM_ROWS][NUM_COLS]);
void translateTriangle (int tranX, int tranY, int original[NUM_ROWS][NUM_COLS], int translated[NUM_ROWS][NUM_COLS]);

/*************************/
/*     MAIN FUNCTION     */
/*************************/
int main () {
    /* set integers */
    int points[NUM_ROWS][NUM_COLS];
    int newpoints[NUM_ROWS][NUM_COLS];
    char axis;
    int reflect, translateX, translateY;

    /* Ask for 3 triangle points, and list them as the starting traingle */
    printf("Enter point #1 as x and y: ");
    scanf("%d %d", &points[0][0], &points[0][1]);
    printf("Enter point #2 as x and y: ");
    scanf("%d %d", &points[1][0], &points[1][1]);
    printf("Enter point #3 as x and y: ");
    scanf("%d %d", &points[2][0], &points[2][1]);

    /* print the starting triangle by calling printTriangle function */
    printf("Starting Traingle: ");
    printTriangle(points);
    /* print a new line */
    printf("\n");

    /* Start the process of rotating the triangle, and printing the rotated triangle */
    printf("Rotated Triangle: ");
    /* call the function to rotate the triangle */
    rotateTriangle(points, newpoints);
    /* call the function to print the rotated triangle */
    printTriangle(newpoints);
    /* print a new line */
    printf("\n");

    /* start the process of reflecting the traingle, and printing the reflected traiangle */
    /* ask the user what axis to reflect the triangle on */
    printf("Enter axis to reflect: ");
    scanf("%s", &axis);
    /* call the function to reflect the triange */
    reflect = reflectTriangle(axis, points, newpoints);
    /* if a valid axis was entered, print the reflected triangle */
    if (reflect == 0) {
      /* print the reflected triangle */
      printf("Reflected Triangle: ");
      printTriangle(newpoints);
      /* if an invalid axis was entered, print 'Invalid Axis' */
    } else {
      /* print that it is an invalid axis */
      printf("Invalid Axis. Next time enter x or y.");
    }
    /* print a new line */
    printf("\n");

    /* start the process of translating the triangle, and printing the translated triangle */
    /*ask the user how many spaces to translate the triangle, in x, and y */
    printf("Enter translation values (x and y): ");
    scanf("%d %d", &translateX, &translateY);
    /* call the function to translate the traingle */
    translateTriangle(translateX, translateY, points, newpoints);
    /* print the translated triangle */
    printf("Translated Triangle: ");
    printTriangle(newpoints);
    /* print a new line */
    printf("\n");

    return 0;
}

/*******************************************************/
/*     This function is used to print the triangle     */
/*******************************************************/
void printTriangle(int points[NUM_ROWS][NUM_COLS]) {
    /* set integers and pointers */
    int x, *p;
    /* set pointer equal to the address of the array */
    p = &points[0][0];
    /* print the points, incriment the row until there are no more rows */
    for (x = 0; x < NUM_ROWS; x++){
      printf("(%d, %d)", *(p + ( x * 2)), *(p + ( x * 2) + 1));
    }
}

/********************************************************/
/*     This function is used to rotate the triangle     */
/********************************************************/
void rotateTriangle(int original[NUM_ROWS][NUM_COLS], int rotated[NUM_ROWS][NUM_COLS]) {
    /* set integers */
    int x;

    /* for-loop to rotate triange */
    for (x = 0 ; x < 3; x++) {
        rotated[x][0] = original[x][1];
        rotated[x][1] = -original[x][0];
    }
}

/*********************************************************/
/*     This function is used to reflect the triangle     */
/*********************************************************/
int reflectTriangle(char reflectAxis, int original[NUM_ROWS][NUM_COLS], int reflected[NUM_ROWS][NUM_COLS]) {
    /* set integers */
    int n;
    /* if-else statement based on which axis the user wants to reflect the triangle on */
    /* if the user selects the x-axis, all x coordinates become negative */
    if (reflectAxis == 'x' || reflectAxis == 'X') {
        for (n = 0; n < 3; n++) {
            reflected[n][0] = original[n][0];
            reflected[n][1] = -original[n][1];
        }
        return 0;
    /* else if the user selects the y-axis, all y coordinates become negative */
  } else if (reflectAxis == 'y' || reflectAxis == 'Y' ) {
        for (n = 0; n < 3; n++) {
            reflected[n][0] = -original[n][0];
            reflected[n][1] = original[n][1];
        }
        return 0;
        /* if user selects anything other than x, or y, print that it is an invalid axis */
    } else {
        return -1;
    }
}

/***********************************************************/
/*     This function is used to translate the triangle     */
/***********************************************************/
void translateTriangle (int tranX, int tranY, int original[NUM_ROWS][NUM_COLS], int translated[NUM_ROWS][NUM_COLS]) {
    int n;
    /* add the translate values to the original coordinates */
    for (n = 0; n < 3; n++) {
        /* translate values. original x coordinate + translate x = new x coordinate */
        translated[n][0] = original[n][0] + tranX;
        /* translate values. original y coordinate + translate y = new y coordinate */
        translated[n][1] = original[n][1] + tranY;
    }
}
