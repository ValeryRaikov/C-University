#include <stdio.h>

int main()
{
    int num1, num2;
    printf("Enter numbers num1 and num2: ");
    do{
        scanf("%d %d", &num1, &num2);
        if (num1 > 0 && num2 > 0)
            break;
        else
        {
            printf("Wrong input! Numbers must be positive. Try again: ");
            scanf("%d %d", &num1, &num2);
        }
    } while (1);

    int number;
    printf("Enter matrix numbers:\n");
    for (int i=0; i<num1; ++i)
    {
        for (int j=0; j<num2; ++j)
        {
            printf("matrix[%d][%d]", i, j);
            scanf("%d", &number);
        }
    }

    printf("This is your matrix:\n");
    for (int i=0; i<num1; ++i)
    {
        for (int j=0; j<num2; ++j)
        {
            printf("matrix[%d][%d] -> %d\t", i, j, number);
        }
        putchar('\n');
    }

    return 0;
}
