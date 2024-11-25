# include <stdio.h>

int main() {
    int m[] = {1, 2, 3, 4, 5};
    int *temp = m;
    int n[5];

    for (int i = 4; i >= 0; i--) {
        n[i] = *temp;
        temp++;
    }

    for (int i = 0; i < 5; i++) {
        printf("%d ", n[i]);
    }

    return 0;
}