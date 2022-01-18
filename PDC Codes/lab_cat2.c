#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>
int main(int argc, char **argv)
{
	// NAME: PUNIT MIDDHA
	// REGNO: 19BCE2060
	
	char msg[20];
	int my_rank, t =99,sum=0;
	int a[101]={0};
	int i=0;
	for(i=0;i<10;i++)
	{
		a[i] = i;
	}
	for(i=0;i<10;i++)
	{
		sum+=a[i];
	}
	
	MPI_Status status;

	// Initialising the MPI program
	MPI_Init(&argc, &argv);
	// Finding the rank for each process
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	
	if (my_rank == 0){
	strcpy(msg, "\nSum of the array: ");
	MPI_Send(msg, strlen(msg)+1, MPI_CHAR, 1, t, MPI_COMM_WORLD);
	}
	
	else if (my_rank == 1){
	MPI_Recv(msg, 20, MPI_CHAR, 0, t, MPI_COMM_WORLD, &status);
	printf("%s: %d\n\n", msg,sum);
	}
	// Ending MPI code
	MPI_Finalize();
}
