# include <stdio.h>

int main() {
    int n[] = {2, 4, 6, 7, 8, 9};
    int *temp = n;
    int sum = 0;
    for (int i = 0; i < 6; i++) {
        sum += *temp;
        temp++;
    }
    
    printf("Sum of the array is %d\n", sum);

    return 0;
}