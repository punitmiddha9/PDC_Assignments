#include <stdio.h>
#include <omp.h>
int main(){
    int i, n;

    printf("\nNAME: PUNIT MIDDHA\n");
    printf("REGNO: 19BCE2060\n\n");

    // Using Predefined Array
    // int array[15] = {18,28,36,15,85,65,445,111,252,782,};

    // Taking User Inputs
    printf("Size the Array: ");
    scanf("%d", &n);

    int array[n];

    printf("\nEnter the Elements of Array: ");

    for(i=0; i<n; i++){
        scanf("%d", &array[i]);
    }

    int small_num = 100, j;
    printf("\n");
    #pragma omp parallel reduction(min : small_num)
    {
        #pragma omp for
        for(j = 0; j < n; j++){
                printf("Value at Index [%d] = %d\n",j,array[j]);
                if(array[j] < small_num){
                    small_num = array[j];
            }
        }
    }
    printf("\n\tMinimum Value in the Given Array = %d\n", small_num);

    printf("\nResult: In the given Question, we have to find the Smallest element using OpenMP program. we have Successfully printed the Smallest element in the Output Screen. \n ");
}

