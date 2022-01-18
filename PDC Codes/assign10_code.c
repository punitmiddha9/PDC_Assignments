#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    //Starting MPI
    MPI_Init(&argc, &argv);

    //Size of processes
    int size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
   
    //Array initialization
    int b[4] ={0,0,0,0};
    if(size != 4)
    {
        printf("Minimum 4 MPI processes required.\n");
        MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
    }
    //Root's rank
    int root = 3;
 
    //Rank of process
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    
    int value = rank * 1;
    printf("Process [%d] \t value = [%d] \n", rank, value);
   
    if(rank == root)
    {
        MPI_Gather(&value, 1, MPI_INT, b, 1, MPI_INT, root, MPI_COMM_WORLD);
        printf("Root process on array %d: [%d,%d,%d,%d] \n\n", rank, b[0], b[1], b[2],b[3]);
    }
    else
    {
        MPI_Gather(&value, 1, MPI_INT, NULL, 0, MPI_INT, root, MPI_COMM_WORLD);
        printf("Elements collected on array process %d: [%d,%d,%d,%d] \n\n", rank, b[0], b[1], b[2],b[3]);
    }
    // End MPI
    MPI_Finalize();
    return EXIT_SUCCESS;
}

