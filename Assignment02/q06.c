# include <stdio.h>

int main() { 
    int n[] = {1, 5, 7, 3, 6, 8};

    int *high = n;
    int *low = n;

    for (int i = 0; i < 6; i++) {
        if (*high < *(n + i)) {
            high = n + i;
        }
        if (*low > *(n + i)) {
            low = n + i;
        }
    }

    printf("Highest number is %d\n", *high);
    printf("Smallest number is %d\n", *low);

    return 0;
}