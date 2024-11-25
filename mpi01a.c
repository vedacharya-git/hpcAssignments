#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    int rank, size, sum = 0, total_sum;

    // Initialize MPI environment
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    sum = rank;

    MPI_Reduce(&sum, &total_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("The sum of ranks across all processes is: %d\n", total_sum);
    }

    MPI_Finalize();
    return 0;
}