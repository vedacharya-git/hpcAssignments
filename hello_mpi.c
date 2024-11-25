#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    MPI_Comm_size(MPI_COMM_WORLD, &size);

    printf("Hello World from processor %d out of %d processors\n", rank, size);

    if (rank == 0) {
        char message[] = "Greetings from Process 0!";
        MPI_Send(message, sizeof(message), MPI_CHAR, 1, 0, MPI_COMM_WORLD);
        printf("Process 0 sent message: %s\n", message);
    } else if (rank == 1) {
        char received_message[50];
        MPI_Recv(received_message, 50, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process 1 received message: %s\n", received_message);
    }

    MPI_Finalize();
    return 0;
}
