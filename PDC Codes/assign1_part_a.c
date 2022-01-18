/*#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{

    printf("\nNAME: PUNIT MIDDHA\n");
    printf("REGNO: 19BCE2060\n\n");

    omp_set_num_threads(10);

    #pragma omp parallel
    {
        printf("Current thread number: %d of [%d]\n", omp_get_thread_num(), omp_get_num_threads());
    }

    return 0;
}*/

//1
/*#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void main() {
int i, num= 5, arr[5]={0,1,2,3,4};
#pragma omp parallel
{
    #pragma omp for
    for(i=0; i<num; i++){
        printf("%d %d \n", i, arr[i]);
    }
}
}*/


//2
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
void main() {
int i, num= 5, arr[5]={10,20,30,40,50}, sum=0;
#pragma omp parallel shared(sum,arr) private(i)
{
    #pragma omp for
    for(i=0; i<num; i++){
            sum+=arr[i];
            printf("%d %d \n", i, sum);
    }
}
}

