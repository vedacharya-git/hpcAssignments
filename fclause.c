#include <stdio.h>
#include <omp.h>

int main() {
    int val = 42;

    printf("Initial value of val outside parallel region: %d\n", val);
    
    #pragma omp parallel private(val)
    {
        int thread_id = omp_get_thread_num();

        val = thread_id * 10;
        printf("Thread %d: val = %d\n", thread_id, val);

        val += 5;
        printf("Thread %d: val after modification = %d\n", thread_id, val);
    }

    printf("Final value of val outside parallel region: %d\n", val);

    return 0;
}
