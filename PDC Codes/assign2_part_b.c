#include<stdio.h>
#include<omp.h>
void main(){
    int i, num;

    printf("\nNAME: PUNIT MIDDHA\n");
    printf("REGNO: 19BCE2060\n\n");

    printf("Enter the Size of an Array: ");
    scanf("%d", &num);

    int array[num], sum=0;

    printf("\nEnter the Elements of Array: ");

    for(i=0; i<num; i++){
        scanf("%d", &array[i]);
    }

    #pragma omp parallel shared(sum,array) private(i)
    {
        #pragma omp for
        for(i=0; i<num; i++){
            sum+=array[i];
            printf("\nSum at %d th Position = %d", i, sum);
        }
    }

    printf("\n");
}
