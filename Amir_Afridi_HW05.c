/*
Amir Afridi
U01470999
Homework 5
COP 3514
*/

/* header files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* constants */
#define NAME_LEN 80

/* Person struct */
struct Person {
  char name[NAME_LEN];
  int age;
};

/* typedef for person struct */
typedef struct Person person;

/* functions */
void printPerson (person *p, int argc);
void bubbleSort (person *p, int size, int option);


/*****************/
/* MAIN FUNCTION */
/*****************/
int main (int argc, char *argv[]) {
  /* integers */
  int i, j;
  /* memory allocation */
  person *p=(person*) malloc(((argc - 1)/ 2) * sizeof(person));

  /* if there is only 1 argument (the program name) or there is an even number
  of arguments (including the program name), then there is an invalid number
  of arguments, and the program will close. */
  if (argc == 1 || argc % 2 == 0) {
    printf("\nInvalid Arguments.");
    printf("\nUsage: ./Amir_Afridi_HW05 name1 age1 name2 age2 ...\n");
    return 0;
  }

  /* print the number of persons that have been entered.
     argc/2 because argc is the number of persons, and the number
     of ages that have been entered */
  printf("You have entered %d person(s) into the program. \n", argc/2);

  /* set names from argc to names of person struct */
  /* initialize j and use it as the incrimenter */
  j = 0;
  /* start at i = 1 for names, and add 2 to i every time, to skip the ages */
  for(i = 1; i < argc; i += 2) {
    strcpy(p[j].name,argv[i]);
    /* incriment j after each itteration of the for-loop */
    j++;
  } /* end of for-loop to copy names to struct */

  /* set ages from argc to ages of person struct */
  /* initialize j and use it as the incrimenter */
  j = 0;
  /* start at i = 2 for ages, and add 2 to i every time, to skip the names */
  for(i = 2; i < argc; i += 2){
    /* convert ages to integers */
    p[j].age = atoi(argv[i]);
    if (p[j].age <= 0) {
      /* 0 is an invalid age.  If any age is 0, close the program */
      /* any letters will become 0 with atoi */
      printf("Invalid age <= 0. Try again.\n");
      return 0;
    }
    /* incriment j after each itteration of the for-loop */
    j++;
  } /* end of for-loop to copy ages to struct */

  /* print unsorted names */
  printf("\nUnsorted Names: \n");
  printPerson(p, j);

  /* print all persons sorted by first name */
  printf("\nSorted by First Name: \n");
  /* call bubbleSort function, and sort with option 1 for name */
  bubbleSort(p, j, 1);
  /* call printPerson function after the struct has been sorted by name */
  printPerson(p, j);

  /* print all persons sorted by age */
  printf("\nSorted by Age: \n");
  /* call bubbleSort function, and sort with option 2 for age */
  bubbleSort(p, j, 2);
  /* call printPerson function after the struct has been sorted by age */
  printPerson(p, j);

  /* print a new line */
  printf("\n");
  /* return 0 to close the program */
  return 0;

} /* end of main function */


/***************************************/
/* printPerson function: used to print */
/**** out the persons name, and age ****/
/***************************************/
void printPerson (person *p, int argc) {
  int i;
  /* int i for incrimenting */
  for(i = 0; i < argc; i++){
    /* print the ith person's name and age */
    printf("Name: %s | Age: %d \n", p[i].name, p[i].age );
  } /* end of for-loop */
} /* end of printPerson function */


/*************************************/
/* bubbleSort function: used to sort */
/***** by either name, or by age *****/
/*************************************/
/*
used website for help with bubbleSort function:
https://www.youtube.com/watch?v=Jdtq5uKz-w4
*/

void bubbleSort (person *p, int size, int option) {

  /* incrimenting integer */
  int i, j;
  /* temporary person used for swapping the order of 2 persons in the struct */
  person temp;

  /* for-loop, to be ran size-1 times */
  for (i = 0; i < size - 1; i++){
    /* incriment j in the for-loop */
    /* incriment j from 0 to size - i - 1 for every itteration of i for-loop */
    for(j = 0; j < size - i - 1; j++) {
      /* if-else statement to determine if the  */
      /* function will sort by name, or by age. */
      if(option == 1) { /* if option 1, sort by name */

        /* if the name in the j+1 spot is after the
        the name in the j spot, swap spots */
        if (strcmp(p[j].name, p[j+1].name)>0) {
          strcpy(temp.name, p[j].name);
          strcpy(p[j].name, p[j+1].name);
          strcpy(p[j+1].name, temp.name);

          temp.age = p[j].age;
          p[j].age = p[j+1].age;
          p[j+1].age = temp.age;
        } /* end of if-loop for sorting by name */

      } else if(option == 2) { /* if option 2, sort by age */

        /* if the age in the j+1 spot is higher than
        the age in the j spot, swap spots */
        if(p[j].age>p[j+1].age) {
          temp.age = p[j].age;
          p[j].age = p[j+1].age;
          p[j+1].age = temp.age;

          strcpy(temp.name, p[j].name);
          strcpy(p[j].name, p[j+1].name);
          strcpy(p[j+1].name, temp.name);

        } /* end of if-loop */
      } /* end of else-if-loop for sorting by age */
    } /* end of inside for-loop */
  } /* end of outsie for-loop */
} /* end of bubbleSort function */
