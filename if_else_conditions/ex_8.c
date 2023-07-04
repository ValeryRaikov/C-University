#include <stdio.h>

int main()
{
    float pipe1, pipe2, hours, length, width, depth, debit, volume;
    printf("Enter pipe debits:\n");
    scanf("%f %f", &pipe1, &pipe2);

    printf("Enter length, width and depth of the pool:\n");
    scanf("%f %f %f", &length, &width, &depth);
    volume = length * width * depth;

    printf("Enter hours:\n");
    scanf("%f", &hours);

    debit = pipe1*hours + pipe2*hours;

    printf("Total debit: %.2f\n", debit);
    printf("Pool volume: %.2f\n", volume);

    float overflow, free_space;
    if (debit > volume)
    {
        overflow = debit - volume;
        printf("Overflow: %.2f", overflow);
    } else
    {
        free_space = volume - debit;
        printf("Free space: %.2f", free_space);
    }

    return 0;
}
