#include <stdio.h>
#include <string.h>
#include <mpi.h>
int main(int argc, char **argv)
{
	// NAME: PUNIT MIDDHA
	// REGNO: 19BCE2060
	
	char message[100];
	int rank, t =99,sum=0;
	int arr[10]={80,58,25,15,23,85,36,1,85,101};
	int i=0;
	
	for(i=0;i<10;i++)
	{
		sum+=arr[i];
	}
	
	MPI_Status status;

	// Initialising the MPI program
	MPI_Init(&argc, &argv);
	// Finding the rank for each process
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	if (rank == 0){
	strcpy(message, "\nSum of the array: ");
	MPI_Send(message, strlen(message)+1, MPI_CHAR, 1, t, MPI_COMM_WORLD);
	}
	
	else if (rank == 1){
	MPI_Recv(message, 20, MPI_CHAR, 0, t, MPI_COMM_WORLD, &status);
	printf("%s: %d\n\n", message, sum);
	}
	// Ending MPI code
	MPI_Finalize();
}
