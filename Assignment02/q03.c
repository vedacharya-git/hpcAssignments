# include<stdio.h>

int main(){
    int m[5] = {1, 2, 3, 4, 5};

    int *temp = m;
    for (int i = 0; i < 5; i++){
        printf("Number %d \n", *temp);
        temp++;
    }

    return 0;
}