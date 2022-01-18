#include <stdio.h>
#include<stdlib.h>
#include <mpi.h>
int main(int argc, char** argv) {   
	//Initailize MPI and finding the rank for each process
        MPI_Init(&argc, &argv);
	int process_rank;
	MPI_Comm_rank(MPI_COMM_WORLD,&process_rank);
	
	char message[30] = "Hello World! REGNO: 19BCE2060";
	const int bcast_root=0;
	
	//Call for root
	if(process_rank == bcast_root) {
		printf("\n[Process Number: %d] From Broadcast Root, Send Message: %s\n\n", process_rank, message);
	}

	//MPI Bcast function
	MPI_Bcast(&message, 1, MPI_CHAR, bcast_root, MPI_COMM_WORLD);

	//After Bcast function
	if(process_rank!=bcast_root){
		printf("[Process Number: %d] From Broadcast Reciever, Obtained Message: %s\n\n", process_rank, message);
	}
	
	//Ending MPI
	MPI_Finalize();
	return 0;
}
