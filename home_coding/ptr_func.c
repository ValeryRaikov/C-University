#include <stdio.h>

float calculate(float *num1, float *num2, char *operation)
{
    float result;
    switch (*operation)
    {
        case('+'):
            result = *num1 + *num2;
            break;
        case('-'):
            result = *num1 - *num2;
            break;
        case('*'):
            result = *num1 * *num2;
            break;
        case('/'):
            result = *num1 / *num2;
            break;
        default:
            puts("Wrong user input!");
    }
    return result;
}

int main()
{
    float num1, num2;
    char operand;
    printf("Enter numbers:\n");
    scanf("%f %f", &num1, &num2);
    printf("Enter operand:\n");
    scanf(" %c", &operand);
    printf("Calculation is: %.2f\n", calculate(&num1, &num2, &operand));

    return 0;
}
