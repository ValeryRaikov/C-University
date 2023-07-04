#include <stdio.h>

int main()
{
    double deg, rad, pi = 3.1415;
    printf("Enter the degrees value: ");
    scanf("%lf", &deg);


    rad = deg * (pi / 180);

    printf("%.2lf degrees is equal to %.2lf radians.", deg, rad);

    return 0;
}
