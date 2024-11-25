# include <stdio.h>

float add(float a, float b) { return a + b;}
float sub(float a, float b) { return a - b;}
float mul(float a, float b) { return a * b;}
float div(float a, float b) { return (float)a / b;}

int main() {
    float (*funcPtr)(float, float);

    float a, b;
    printf("Enter two numbers: ");
    scanf("%f %f", &a, &b);

    char cont = 'y';

    while (cont == 'y')
    {
        printf("Enter the operation you want to perform:\n");
        printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            funcPtr = &add;
            break;
        case 2:
            funcPtr = &sub;
            break;
        case 3:
            funcPtr = &mul;
            break;
        case 4:
            funcPtr = &div;
            break;
        default:
            printf("Invalid choice\n");
            break;
        }

        float result = funcPtr(a, b);
        printf("The result is: %f\n", result);

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &cont);
    }

    return 0;
}