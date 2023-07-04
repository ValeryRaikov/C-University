#include <stdio.h>

int main ()
{
    //Rectangulare
    int a, b, area;
    printf("Enter sides: \n");
    scanf("%d %d", &a, &b);
    printf("a=%d, b=%d\n", a, b);

    area = a * b;
    printf("Area is: %d\n", area);

    //Circle
    float diameter, length, pi = 3.1415;
    printf("Enter diameter: \n");
    scanf("%f", &diameter);
    printf("d=%.2f\n", diameter);

    length = pi * diameter;
    printf("Lenght is: %.2f\n", length);

    //Whole number operation
    int num;
    printf("Enter number: \n");
    scanf("%d", &num);
    printf("number=%d\n", num);

    if ((num % 8) > 4)
        printf("Error");

    return 0;
}
