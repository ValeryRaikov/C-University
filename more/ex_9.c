#include <stdio.h>

void digits(int n)
{
    int first_digit = n/10;
    int second_digit = n%10;
    printf("First digit ->%d, second digit->%d", first_digit, second_digit);
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
    digits(number);

    return 0;
}

