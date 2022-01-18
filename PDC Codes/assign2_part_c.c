#include<stdio.h>
#include<omp.h>
void main(){
    int i, num;

    printf("\nNAME: PUNIT MIDDHA\n");
    printf("REGNO: 19BCE2060\n\n");

    printf("Enter the Size of an Array: ");
    scanf("%d", &num);

    int array[num], product=1;

    printf("\nEnter the Elements of Array: ");

    for(i=0; i<num; i++){
        scanf("%d", &array[i]);
    }

    #pragma omp parallel shared(product,array) private(i)
    {
        #pragma omp for
        for(i=0; i<num; i++){
            product*=array[i];
            printf("\nProduct at %d th Position = %d", i, product);
        }
    }

    printf("\n");
}
