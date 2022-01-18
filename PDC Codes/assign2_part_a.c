#include<stdio.h>
#include<omp.h>
void main(){
    int i, num;

    printf("\nNAME: PUNIT MIDDHA\n");
    printf("REGNO: 19BCE2060\n\n");

    printf("Enter the Size of an Array: ");
    scanf("%d", &num);

    int arr[num];

    printf("\nEnter the Elements of Array: ");

    for(i=0; i<num; i++){
        scanf("%d", &arr[i]);
    }

    #pragma omp parallel
    {
        #pragma omp for
        for(i=0; i<num; i++)
        printf("\n\t%d at Position [%d]", arr[i], i);
    }

    printf("\n");
}
