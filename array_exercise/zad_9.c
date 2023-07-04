#include <stdio.h>

void digits(int *a, int *b, int n)
{
    int *ptr_a;
    int *ptr_b;
    ptr_a = &a;
    ptr_b = &b;
    *ptr_a = n/10;
    *ptr_b = n%10;
    printf("First digit -> %d, second digit-> %d", *ptr_a, *ptr_b);
}

int main()
{
    int number;
    printf("Enter the number:\n");
    scanf("%d", &number);
    while (1)
    {
        if(number<=0)
        {
            printf("Number must be positive!\n");
            scanf("%d", &number);
        }
        else
            break;
    }
    int num[2];
    num[0]= number/10;
    num[1]= number%10;

    digits(num[0], num[1], number);

    return 0;
}


