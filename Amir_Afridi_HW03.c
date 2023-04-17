/*
 Amir Afridi
 U01470999
 Homework 3
 COP 3514
 */


#include <stdio.h>
#include <math.h>

/* program functions */
int quadraticFormula(float a, float b, float c, float *root1, float *root2);
void quadraticVertex(float a, float b, float c, float *x, float *y);
void quadraticInfo(float a, float b, float c, float *directrix, char *direction, int x, int y);

/*************************/
/***** MAIN FUNCTION *****/
/*************************/
int main() {
    int a, b, c, root;
    float root1, root2, x, y, directrix;
    char direction;
    /* Ask for a, b, and c */
    printf("Enter coefficients a, b and c: ");
    scanf("%d %d %d",&a, &b, &c);
    if (a == 0) {
        /* a can not equal 0 for quadratic formula */
        printf("a can not equal 0 \n");
        return 0;
    }

    /* run quadraticFormula function */
    root = quadraticFormula(a,b,c,&root1,&root2);

    /* print quadratic equation */
    printf("f(x) = %dx^2 + %dx + %d \n",a,b,c);
    /* if else statement prints the root(s) */
    if(root == 2) {
        printf("Roots: %.2lf and %.2lf \n",root1 , root2);
    }
    else if(root == 1) {
        printf("Root: %.2lf \n", root1);
    }
    else {
        printf("No real roots \n");
    }

    /* calls the quadraticVertex function */
    quadraticVertex(a,b,c,&x,&y);
    /* prints the vertex */
    printf("Vertex: (%0.2lf, %0.2lf) \n",x,y);

    /* calls the quadraticInfo function */
    quadraticInfo(a,b,c,&directrix,&direction,x,y);

    /* prints the directrix */
    printf("Directrix: y = %0.2lf \n",directrix);

    /* prints the direction that the parabola is open to. */
    if(direction == 'D')
        printf("The Graph is facing down \n");
    else if(direction == 'U')
        printf("The Graph is facing up \n");

    return 0;
}

/***************************************************/
/***** This function is used to find the roots *****/
/***************************************************/
int quadraticFormula(float a, float b, float c, float *root1, float *root2) {

    float determinant;
    /* calculate the determinant(s) */
    determinant = b*b-4*a*c;

    /* conditions for the number of determinants there are */
    if (determinant > 0)
    {
        /* find the roots */
        /* sqrt function finds the square root */
        *root1 = (-b+sqrt(determinant))/(2*a);
        *root2 = (-b-sqrt(determinant))/(2*a);

        return 2;
    }

    /* condition for real or equal roots */
    else if (determinant == 0)
    {
        *root1 = *root2 = -b/(2*a);
        return 1;
    }

    /* condition for no real roots */
    else
    {
        return 0;
    }
}

/****************************************************/
/***** This fucntion is used to find the vertex *****/
/****************************************************/
void quadraticVertex(float a, float b, float c, float *x, float *y) {
    /* used to calculate the x coordinate */
    *x = b/a;
    *x = *x/2;
    *x = -1*(*x);

    /* used to calculate the y coordinate */
    *y = pow(*x,2)*a - c;
    *y = -1*(*y);
}

/********************************************************************************/
/***** This function is used to find directix and direction of the equation *****/
/********************************************************************************/
void quadraticInfo(float a, float b, float c, float *directrix, char *direction, int x, int y){
    float p = 1/(4*a);

    /* used to find the directrix */
    *directrix = y - p;

    /* Determines whether the parabola is facing up or down */
    if( p < 0)
        *direction = 'D';
    else if( p > 0)
        *direction = 'U';

}
