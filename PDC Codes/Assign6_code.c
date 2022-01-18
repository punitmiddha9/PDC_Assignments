#include<stdio.h>
#include<mpi.h>
#include<stdlib.h>

int main(int argc, char **argv){
	int Process_Rank, Cluster_Size;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &Process_Rank);
	MPI_Comm_size(MPI_COMM_WORLD, &Cluster_Size);
	printf("\n\tHello World from Rank(processor number) %d of Cluster size [%d]\n", Process_Rank, Cluster_Size);
	printf("\n");
	MPI_Finalize();
	return 0;
}
