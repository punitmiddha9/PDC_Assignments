#include <stdio.h>
#include <omp.h>
int main(void){
    int i, n;

    printf("\nNAME: PUNIT MIDDHA\n");
    printf("REGNO: 19BCE2060\n\n");

    printf("Enter the Size of an Array: ");
    scanf("%d", &n);

    int arr[n], sum=0;

    printf("\nEnter the Elements of Array: ");

    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    int max_value, j, min_value;
    #pragma omp parallel reduction(max : max_value) reduction(min: min_value)
    {
        #pragma omp for
        for(j = 0; j < n; j++){
            printf("Array Value at Index %d = %d\n",j,arr[j]);
            #pragma omp critical
            {
                if(arr[j] > max_value){
                    max_value = arr[j];
                }
                if(arr[j] < min_value){
                    min_value = arr[j];
                }
            }
        }
    }
    printf("\n\tMaximum value = %d\n", max_value);
    printf("\n\tMinimum value = %d\n", min_value);
}
