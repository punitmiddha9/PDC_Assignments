#include<stdio.h>
#include <omp.h>
void main(){

    printf("\nNAME: PUNIT MIDDHA\n");
    printf("REGNO: 19BCE2060\n\n");

    int a,b;
    printf("Enter the Value of A: ");
    scanf("%d", &a);
    printf("Enter the Value of B: ");
    scanf("%d", &b);
    int sum, sub, mply, div;

    #pragma omp parallel
    {
        #pragma omp sections
        {
            #pragma omp section
            sum = a+b;
            #pragma omp section
            sub = a-b;
            #pragma omp section
            mply = a*b;
            #pragma omp section
            div = a/b;
        }
    }
    printf("\nADDITION of %d and %d is: %d", a, b, sum);
    printf("\nSUBSTRATION of %d and %d is: %d", a, b, sub);
    printf("\nMULTIPLICATION of %d and %d is: %d", a, b, mply);
    printf("\nDIVISION of %d and %d is: %d\n\n", a, b, div);
}
