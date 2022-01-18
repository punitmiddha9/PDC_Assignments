#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<mpi.h>
int main(int argc, char* argv[]) {
	int rank, num_of_procs, i;
	//Intializing MPI
	MPI_Init(&argc, &argv);
	
	//Rank and Size of process
	MPI_Comm_size(MPI_COMM_WORLD, &num_of_procs);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	//Variables Declarations
	int local_sum = 0; 
	int global_sum = 0;
	int a[] = { 5, 2, 7, 4 };
	char o;
	
	if (rank == 0) {
		printf("Addition of the array using MPI_Reduce \n");
	}
	//Addition of elements in an array
	for (i = rank; i < 4; i += num_of_procs) {
		printf("array[%d]: %d\n",i, a[i]);
		local_sum = local_sum + a[i];
	}
	//MPI Reduce function
	MPI_Reduce(&local_sum, &global_sum, 3, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	//Print final sum
	if (rank == 0) {
	printf("Global Sum: %d\n", global_sum);
	}
	//Ending MPI
	MPI_Finalize();
	return 0;
}
