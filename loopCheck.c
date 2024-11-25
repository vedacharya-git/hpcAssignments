#include <stdio.h>
#include <omp.h>

int main() {
    int i, n = 16;           // Number of iterations
    int chunk = 4;           // Size of each chunk
    int results[16] = {0};   // Array to store results

    #pragma omp parallel for schedule(static, chunk)
    for (i = 0; i < n; i++) {
        int thread_id = omp_get_thread_num();
        results[i] = thread_id;
        printf("Iteration %d processed by thread %d\n", i, thread_id);
    }

    printf("\nFinal Results:\n");
    for (i = 0; i < n; i++) {
        printf("results[%d] = %d\n", i, results[i]);
    }

    return 0;
}
