#include <stdio.h>

int calculate(int*, int*, char);

void main()
{
    int num1, num2;
    char operation;
    printf("Enter values for num1 and num2:\n");
    scanf("%d %d", &num1, &num2);
    printf("Enter operator sign:\n");
    scanf(" %c", &operation);
    int result = calculate(num1, num2, operation);
    printf("Final: %d", result);

}
int calculate(int* a, int* b, char opr)
{
    int res;
    int* ptr_a;
    int* ptr_b;
    ptr_a = &a;
    ptr_b = &b;

    switch (opr)
    {
    case '+':
        res = *ptr_a + *ptr_b;
        break;
    case '-':
        res = *ptr_a - *ptr_b;
        break;
    case '*':
        res = *ptr_a * *ptr_b;
        break;
    case '/':
        res = *ptr_a / *ptr_b;
        break;
    default:
        printf("Wrong input!");
    }
    return res;
}
