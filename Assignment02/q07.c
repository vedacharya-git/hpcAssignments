#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int main() {
    int (*funcPtr)(int, int);

    funcPtr = &add;

    int x = 10, y = 20;
    int result = funcPtr(x, y);

    printf("The sum of %d and %d is: %d\n", x, y, result);

    return 0;
}
