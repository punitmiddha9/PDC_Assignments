#include <stdio.h>
#include<omp.h>
int main(void)
{
    printf("\nNAME: PUNIT MIDDHA\n");
    printf("REGNO: 19BCE2060\n\n");

    #pragma omp parallel
    {
        int i;
        #pragma omp for schedule(static,1)
        for(i=0;i<5;i++){
            for(i=0;i<6;i++){
                printf("* ");
            }
            printf("\n");
        }
    }
}
