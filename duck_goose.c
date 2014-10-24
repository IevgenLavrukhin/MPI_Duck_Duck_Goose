#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <mpi.h>
#include <unistd.h>

int main(int argc, char** argv) {

	int my_rank; // rank of the processor
	int size; // number of processors
	int source; // sending processor // rank of the sender 
	int dest; // dest of the message // rank of the processor
	int tag = 50; // Teg of the message
	char message[100]; //for message

	MPI_Status status; // Статус возврата
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size); 

	dest = rand() % ((size-1)+1);

	if (my_rank == 0) {
		sprintf(message, "Hello from the processor %d to the processor %d!", my_rank, dest);
		MPI_Send(message, strlen(message)+1, MPI_CHAR, dest, tag, MPI_COMM_WORLD);
	} 
	
	if (my_rank == dest) source = 0;
	if (my_rank != dest) source = my_rank-1;
	
	MPI_Recv(message, 100, MPI_CHAR,source, tag, MPI_COMM_WORLD, &status);
     	printf("Rank %d =>  obtaine the Message:<< %s >>\n",my_rank,  message);
		
	sleep (3);

	sprintf(message, "Hello from the processor %d to the processor %d!", my_rank, (my_rank+1) % size);
        MPI_Send(message, strlen(message)+1, MPI_CHAR, (my_rank+1)%size, tag, MPI_COMM_WORLD);
 	
	MPI_Finalize();

return 0;
} 






 






