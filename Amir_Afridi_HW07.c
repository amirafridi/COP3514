/*
Amir Afridi
U01470999
Homework 6
COP 3514
*/

/* header files */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* functions */
void counter (FILE *fp);

/*****************
 * MAIN FUNCTION *
 *****************/
int main (int argc, char *argv[]) {

  /* file pointer */
  FILE *fp;

  /* verify that user only entered 1 file name */
  if (argc != 2) {
    printf ("Enter 1 text file to open \n");
    exit(EXIT_FAILURE);
  } /* end of if-loop */

  /* check if file can be opened */
  fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("%s cannot be opened \n", argv[1]);
    exit(EXIT_FAILURE);
  } /* end of if-loop */
  else {
    printf("%s can be opened \n", argv[1]);
  } /* end of else-loop */

  /* call counter function */
  counter (fp);

  /* close file and close program */
  fclose(fp);
  return 0;

} /* end of main function */

/************************************************************************
 * Counter function to count the number of characters, words, and lines *
 *             in the file that is being opened, and read.              *
 *   counter function is also used to print the number of characters,   *
 *                           words, and lines                           *
 ************************************************************************/
void counter (FILE *fp) {

  /* variables */
  char ch;
  int numChars = 0;
  int numWords = 0;
  int numLines = 0;
  /* flag for counting new words */
  int newWord = 0;

  /* while loop to count characters, words, and lines */
  while ((ch = getc(fp)) != EOF) {
    /* incriment character counter for each time the while loop is ran */
    numChars++;

  /***************************************************************************
   * newWord is used as a flag to count a word when it hits an alphabetical  *
   * character.  When it hits an alphabetical character it counts a new word *
   * and then turns the flag to 1, so it does not count a new word for every *
   * letter in the word.  The flag will change to 0 when it hits the first   *
   * space character or punctuation.                                         *
   ***************************************************************************/
  if (newWord == 0) {
    if (isalnum(ch)) {
      numWords += 1;
      /* turn newWord flag on */
      newWord = 1;
    } /* end of if-loop for isalpha */
  } /* end of newWord == 0 if-loop */

  if (newWord == 1) {
    if (isspace(ch) || ispunct(ch)) {
      /* turn newWord flag off */
      newWord = 0;
    } /* end of if-loop for isspace || ispunct */
  } /* end of newWord == 1 if-loop */

    /* incriment line counter for each line */
    if (ch == '\n') {
      numLines++;
    } /* end of if-loop to count lines */
  } /* end of while-loop */

  /* print the number of characters, words, and lines */
  printf("Number of characters: %d\n", numChars);
  printf("Number of words: %d\n", numWords);
  printf("Number of lines: %d\n", numLines);

} /* end of counter function */
