#include <stdio.h>

int main ()
{
    float number, bonus, add_bonus, total;
    printf("Enter number\n");
    scanf("%f", &number);

    if (number <= 100)
        bonus = 5.0;
    else if (number <= 1000)
        bonus = 0.2 * number;
    else if (number > 1000)
        bonus = 0.1 * number;

    total = number + bonus;

    if ((int)number % 2==0)
        add_bonus = 1;
    else if ((int)number % 10==5)
        add_bonus = 2;

    total += add_bonus;

    printf("Bonus = %.2f\n", bonus);
    printf("Additional bonus = %.2f\n", add_bonus);
    printf("Total points = %.2f", total);

    return 0;
}
