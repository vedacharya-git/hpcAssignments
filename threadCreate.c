#include <stdio.h>
#include <omp.h>

int main() {
    int n = 5; // Number of terms

    #pragma omp parallel
    {
        #pragma omp sections
        {
            // first series
            #pragma omp section
            {
                printf("Thread %d: Printing Series 1 (Odd numbers):\n", omp_get_thread_num());
                for (int i = 1; i <= n; i++) {
                    printf("Series 1: %d\n", 2 * i - 1); // Odd numbers
                }
            }

            // second series
            #pragma omp section
            {
                printf("Thread %d: Printing Series 2 (Even numbers):\n", omp_get_thread_num());
                for (int i = 1; i <= n; i++) {
                    printf("Series 2: %d\n", 2 * i); // Even numbers
                }
            }
        }
    }

    return 0;
}
