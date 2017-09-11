#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv)
{
	// Initialize the MPI environment
	// MPI_Init(int* argc, char*** argv) <<<--- wat?
	MPI_Init(NULL, NULL);

	// Get the number of processes
	// XXX: I presume that MPI_Init registers this process as an MPI
	// process, and therefore this number increases and decreases as
	// processes Init and Finalize?
	int world_size;
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	// Get the rank of the process
	// XXX: I presume the rank is either set manually (1 of the NULLs in Init?)
	// or by order of registration.  
	int world_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

	// Get the name of the processor
	char processor_name[MPI_MAX_PROCESSOR_NAME];
	int name_len;
	MPI_Get_processor_name(processor_name, &name_len);

	// Print off hello world message
	printf("Hello world from processor %s, rank %d"
			" out of %d processors\n",
			processor_name, world_rank, world_size);

	// Finalize the MPI environment
	MPI_Finalize();
}
