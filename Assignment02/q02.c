#include <stdio.h>

int main() {
    int m, n;
    m = 5;
    n = 10;
    printf("m = %d, n = %d\n", m, n);

    // Swap the values of m and n
    int temp;
    temp = m;
    *(&m) = *(&n);
    *(&n) = temp;

    printf("m = %d, n = %d\n", m, n);

    return 0;
}