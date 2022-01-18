#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void invoke(){
    printf("Hello World from Core:\)\n");
}

int main()
{

    printf("\nNAME: PUNIT MIDDHA\n");
    printf("REGNO: 19BCE2060\n\n");

    printf("Hello World!!!\n\n");

    #pragma omp parallel
    {
        printf(" %d ", omp_get_thread_num());
        invoke();
    }

    return 0;
}
