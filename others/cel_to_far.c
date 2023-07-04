#include <stdio.h>

int main()
{
    double cel, far;
    printf("Enter the celsius value: ");
    scanf("%lf", &cel);

    double div = (double)9 / 5;
    far = cel * div + 32;

    printf("%.2lf celsius is equal to %.2lf farenheits.", cel, far);

    return 0;
}
