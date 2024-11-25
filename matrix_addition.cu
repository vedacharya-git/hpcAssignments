#include <stdio.h>
#include <cuda.h>

__global__ void matrixAdd(float *A, float *B, float *C, int rows, int cols) {
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;

    int idx = row * cols + col;

    if (row < rows && col < cols) {
        C[idx] = A[idx] + B[idx];
    }
}

int main() {
    int rows = 4;
    int cols = 4;
    int size = rows * cols * sizeof(float);

    float h_A[16] = {1, 2, 3, 4,
                    5, 6, 7, 8,
                    9, 10, 11, 12,
                    13, 14, 15, 16};
    float h_B[16] = {16, 15, 14, 13,
                    12, 11, 10, 9,
                    8, 7, 6, 5,
                    4, 3, 2, 1};
    float h_C[16];

    float *d_A, *d_B, *d_C;
    cudaMalloc((void **)&d_A, size);
    cudaMalloc((void **)&d_B, size);
    cudaMalloc((void **)&d_C, size);

    cudaMemcpy(d_A, h_A, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, h_B, size, cudaMemcpyHostToDevice);

    dim3 blockDim(2, 2); // Block of 2x2 threads
    dim3 gridDim((cols + blockDim.x - 1) / blockDim.x,
                (rows + blockDim.y - 1) / blockDim.y);

    matrixAdd<<<gridDim, blockDim>>>(d_A, d_B, d_C, rows, cols);

    cudaMemcpy(h_C, d_C, size, cudaMemcpyDeviceToHost);

    printf("Resulting matrix C:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2f ", h_C[i * cols + j]);
        }
        printf("\n");
    }

    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);

    return 0;
}
