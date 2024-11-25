#include <stdio.h>
#include <omp.h>

int main() {
    // number of threads set to 4
    omp_set_num_threads(4);

    char *name[] = {"John", "Doe", "Smith", "Brown"};

    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num(); // Get the thread ID
        printf("Thread %d: %s\n", thread_id, name[thread_id]);
    }

    return 0;
}
