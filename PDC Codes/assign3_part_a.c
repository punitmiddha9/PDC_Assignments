#include <omp.h>
#include <stdio.h>
int main()
{
int i, j, n;

    printf("\nNAME: PUNIT MIDDHA\n");
    printf("REGNO: 19BCE2060\n\n");

    printf("Enter the Size of an Array: ");
    scanf("%d", &n);

    int arr[n], sum=0;
    printf("\nEnter the Elements of Array: ");
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("The numbers whose sum is to be found: \n\n\t");
    for (j=0; j< 5; j++){
        printf("%d+",arr[j]);
    }
    printf("\n\n");

    #pragma omp parallel for reduction(+:sum)
    for (j=0; j < n; j++){
    printf("Array Value at Index %d = %d\n",j,arr[j]);
    sum+=arr[j];
    }
    printf("\n\n\tSum of given numbers is = %d\n",sum);

}
