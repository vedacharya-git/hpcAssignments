#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int rank, size;
    int tag = 0;
    int partial_sum, total_sum = 0;
    int next, prev;
    
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    next = (rank + 1) % size;
    prev = (rank - 1 + size) % size;

    partial_sum = rank + 1;

    if (rank == 0) {
        int running_sum = partial_sum;
        MPI_Send(&running_sum, 1, MPI_INT, next, tag, MPI_COMM_WORLD);
        MPI_Recv(&total_sum, 1, MPI_INT, prev, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    } else {
        int incoming_sum;
        MPI_Recv(&incoming_sum, 1, MPI_INT, prev, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        incoming_sum += partial_sum;
        MPI_Send(&incoming_sum, 1, MPI_INT, next, tag, MPI_COMM_WORLD);

        if (rank == size - 1) {
            total_sum = incoming_sum;
        }
    }

    if (rank == 0) {
        printf("The total sum of all ranks is: %d\n", total_sum);
    }

    MPI_Finalize();
    return 0;
}
