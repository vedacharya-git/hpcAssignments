#include <stdio.h>
#include <cuda.h>

__global__ void matrixMultiply(float *A, float *B, float *C, int rowsA, int colsA, int colsB) {
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;

    if (row < rowsA && col < colsB) {
        float sum = 0.0;
        for (int i = 0; i < colsA; i++) {
            sum += A[row * colsA + i] * B[i * colsB + col];
        }
        C[row * colsB + col] = sum;
    }
}

int main() {
    int rowsA = 3, colsA = 3;
    int rowsB = 3, colsB = 3;
    int rowsC = rowsA, colsC = colsB;
    int sizeA = rowsA * colsA * sizeof(float);
    int sizeB = rowsB * colsB * sizeof(float);
    int sizeC = rowsC * colsC * sizeof(float);

    float h_A[] = {1, 2, 3,
                4, 5, 6,
                7, 8, 9};
    float h_B[] = {9, 8, 7,
                6, 5, 4,
                3, 2, 1};
    float h_C[9];

    float *d_A, *d_B, *d_C;
    cudaMalloc((void **)&d_A, sizeA);
    cudaMalloc((void **)&d_B, sizeB);
    cudaMalloc((void **)&d_C, sizeC);

    cudaMemcpy(d_A, h_A, sizeA, cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, h_B, sizeB, cudaMemcpyHostToDevice);

    dim3 blockDim(16, 16);
    dim3 gridDim((colsC + blockDim.x - 1) / blockDim.x,
                (rowsC + blockDim.y - 1) / blockDim.y);

    matrixMultiply<<<gridDim, blockDim>>>(d_A, d_B, d_C, rowsA, colsA, colsB);

    cudaMemcpy(h_C, d_C, sizeC, cudaMemcpyDeviceToHost);

    printf("Resulting matrix C:\n");
    for (int i = 0; i < rowsC; i++) {
        for (int j = 0; j < colsC; j++) {
            printf("%.2f ", h_C[i * colsC + j]);
        }
        printf("\n");
    }

    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);

    return 0;
}
