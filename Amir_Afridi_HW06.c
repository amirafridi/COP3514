/*
Amir Afridi
U01470999
Homework 6
COP 3514
*/

/* Header files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Define Macros */
#define MAX_LEN   20 /* max length of word */
#define MAX_WORDS 50 /* max number of words */

/* Functions */
int readLine();

/* global variables */
char *word[MAX_WORDS];
int num_words = 0;

/*****************/
/* MAIN FUNCTION */
/*****************/
int main() {
  /* variables */
  int smallest, i, j;
  char *temp;

  /* for-loop to enter words */
  for (i = 0; ; i++) {
    word[i] = malloc(i * sizeof(char));
    /* Ask user to enter a word */
    printf("Enter a word: ");
      /* call readLine function */
      if (readLine() == 0) {
        /* if user doesn't enter anything, break. */
        break;
      } /* end of if-loop */
  } /* end of for-loop */

  /* Bubble sorting of words */
  /* for-loop to bubble sort.  Outside incrimenter */
  for (i = 0; i < num_words; i++) {
    smallest = i;
    /* inside incrimenter for bubble sort */
    for (j = (i + 1); j < num_words; j++) {
      if (strcmp(word[j], word[smallest]) < 0) {
        /* swapping words using temp */
        smallest = j;
        temp = word[i];
        word[i] = word[smallest];
        word[smallest] = temp;
      } /* end of if-loop */
    } /* end of inside for-loop */
  } /* end of outside for-loop */

  /* print words in alphabetical order */
  printf("In sorted order: ");
  for (i = 0; i < num_words; i++) {
    printf("%s%s", word[i], i == num_words ? "" : " ");
  } /* end of for-loop */
  puts("\n");
  free (word[i]);
  return 0;
} /* end of main function */

int readLine(char str[], int n) {
  /* memory allocation */
  word[num_words] = malloc(MAX_LEN + 1);
  /* variables */
  int ch, i = 0;

  /* if memory can not be allocated, exit program */
  if (!word[num_words]) {
    printf("Memory allocation error.\n");
    exit(EXIT_FAILURE);
  } /* end of if-loop */
  /* while loop for read function, to check if there is a word entered. */
  while ((ch = getchar()) != '\n')
      if (i < n)
          word[num_words][i++] = ch;
      else if (ch == ' ')
          break;
  word[num_words][i] = '\0';
  num_words++;
  /* return number of letters in string */
  return i;
} /* end of readLine function */
