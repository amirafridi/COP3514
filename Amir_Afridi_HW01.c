/*
 Amir Afridi 
 U01470999
 Homework 1
 COP 3514
*/


/*
 This program will ask the user for 2 fractions, and calculate the sum, difference, product, and quotient 
 of the 2 fractions.  After that, it will state if fraction 1 is an improper fraction or not, and print the 
 improper fraction.  Next, it will print out fraction 1 as a decimal.
 
 Lastly, it will ask the user to enter a GPA for a class, and convert that number into a letter grade.
*/
#include <stdio.h>

int main()
{
/* set variables */
    float numerator1f;
    float denominator1f;
    int numerator1;
    int denominator1;
    int numerator2;
    int denominator2;
    int grade;
    float fraction1;
    int divisionnumerator;
    int divisiondenominator;
    int multiplynumerator;
    int additionnumerator;
    int multiplydenominator;
    int subtractnumerator;
    int mixwhole;
    float mixnum;
    
/* Get fraction 1 and fraction 2 */
    printf("Enter fraction 1: ");
    scanf("%f/%f",&numerator1f,&denominator1f);
    
    printf("Enter fraction 2: ");
    scanf("%d/%d",&numerator2,&denominator2);
/* print out the fractions */
    printf("Fraction number 1: %.0f/%.0f\n",numerator1f,denominator1f);
    printf("Fraction number 2: %d/%d\n",numerator2,denominator2);
/* Calculate math */
/* make float numbers into integers to use remainder calculation */
    numerator1=numerator1f;
    denominator1=denominator1f;
/* division of numerator 1 and denominator 1 to get decimal */
    fraction1=(numerator1f)/(denominator1f);
/* find the numerator of the division of 2 fractions */
    divisionnumerator=(numerator1)*(denominator2);
/* find the denominator of the division of 2 fractions */
    divisiondenominator=(denominator1)*(numerator2);
/* find the numerator of the 2 fractions multiplied */
    multiplynumerator=(numerator1)*(numerator2);
/* find the numerator of the 2 fractions added together */
    additionnumerator=(numerator1)*(denominator2)+(numerator2)*(denominator1);
/* find the denominator of the 2 fractions multiplied */
    multiplydenominator=(denominator1)*(denominator2);
/* find the numerator of fraction 1 - fraction 2 */
    subtractnumerator=(numerator1)*(denominator2)-(numerator2)*(denominator1);
/* find the remained of the first fraction */
    mixnum=numerator1%denominator1;
/* division of the first fraction for a decimal */
    mixwhole=numerator1/denominator1;

/* print the sum, difference, product, and quotient of the 2 fractions */
    printf("addition of fractions: %d/%d\n",additionnumerator,multiplydenominator);
    printf("subtraction of fractions: %d/%d\n",subtractnumerator,multiplydenominator);
    printf("multiplication of fractions: %d/%d\n",multiplynumerator,multiplydenominator);
    printf("division of fractions: %d/%d\n",divisionnumerator,divisiondenominator);
/* 
 if numerator is greater than the denominator for the first fraction
 state that it is an improper fraction, and show the mixed number.
 
 if the numerator is less than the denominator, print that it is not an improper fraction
*/
    if( numerator1 > denominator1 ) {
        printf("Fraction 1 is an imporper fraction" );
        
        if (mixnum == 0) {
            printf("Fraction 1 as a mixed number: %d\n",mixwhole);
        }
        else {
            printf("Fraction 1 as a mixed number: %d %.0f/%d\n",mixwhole, mixnum, denominator1);}
        }
    else {
        printf("Fraction 1 is not an improper fraction: \n");
    }
/* print fraction 1 as a decimal */
    printf("Decimal approximation of Fraction 1: %.2f  \n",fraction1);
/* ask for a grade as an integer between 0 and 4 */
    printf("Enter in a GPA for the class (0-4 integer): ");
    scanf("%d",&grade);
/* print the letter grade that corresponds to the number grade entered. */
    if (grade == 4) {
        printf("You got an A! \n");
    } else if (grade == 3) {
        printf("You got a B! \n");
    } else if (grade == 2) {
        printf("You got a C! \n");
    } else if (grade == 1) {
        printf("You got a D! \n");
    } else if (grade == 0) {
        printf("You got a F! \n");
    } else {
        printf("That isn't a grade \n");
    }
               
               
               
    return 0;
               
}
