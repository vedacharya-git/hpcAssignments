#include <mpi.h>
#include <stdio.h>

int calculate_partial_sum(int start, int end) {
    int sum = 0;
    for (int i = start; i <= end; i++) {
        sum += i;
    }
    return sum;
}

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int N = 100; // Total sum of first N integers
    int chunk_size = N / size;
    int remainder = N % size;

    int start, end;
    if (rank < remainder) {
        start = rank * (chunk_size + 1) + 1;
        end = start + chunk_size;
    } else {
        start = rank * chunk_size + remainder + 1;
        end = start + chunk_size - 1;
    }

    int local_sum = calculate_partial_sum(start, end);

    int global_sum = 0;
    MPI_Reduce(&local_sum, &global_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("The sum of the first %d integers is: %d\n", N, global_sum);
    }

    MPI_Finalize();
    return 0;
}
