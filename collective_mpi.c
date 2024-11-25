#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size;
    int send_data, recv_data[10];

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    MPI_Comm_size(MPI_COMM_WORLD, &size);

    send_data = rank * 10;

    MPI_Gather(&send_data, 1, MPI_INT, recv_data, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Collected data at root process:\n");
        for (int i = 0; i < size; i++) {
            printf("Process %d sent data: %d\n", i, recv_data[i]);
        }
    }

    MPI_Finalize();
    return 0;
}
