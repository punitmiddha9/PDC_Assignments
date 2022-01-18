#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{

    printf("\nNAME: PUNIT MIDDHA\n");
    printf("REGNO: 19BCE2060\n\n");

    int IsNested = omp_get_nested();
    if(IsNested == 1)
        printf("Nested Parallelism: True! \n");
    else
        printf("Nested Parallelism: False! \n\n");


    #pragma omp parallel
    {
        printf("Number of Processors : %d\n",omp_get_num_procs());
        printf("Dynamic Adjustment(0 represents disabled, 1 represents Enabled): %d\n\n",omp_get_dynamic());
    }
    return 0;
}
