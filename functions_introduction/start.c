#include <stdio.h>

float square(float);
float rectangular(float, float);
float triangle(float, float);
float circle(float);

int main()
{
    int number;
    printf("Enter number:\n");
    scanf("%d", &number);

    float result;
    switch (number)
    {
    case 1:
        result = square(5);
        printf("%.2f", result);
        break;
    case 2:
        result = rectangular(5, 10);
        printf("%.2f", result);
        break;
    case 3:
        result = triangle(5, 3);
        printf("%.2f", result);
        break;
    case 4:
        result = circle(9);
        printf("%.2f", result);
        break;
    default:
        printf("Wrong input!\n");
    }

    return 0;
}

float square(float a)
{
    float res = a*a;
    return res;
}
float rectangular(float a, float b)
{
    float res = a * b;
    return res;
}
float triangle(float a, float b)
{
    float res = (a * b)/2;
    return res;
}
float circle(float r)
{
    float res = 3.1415 * r*r;
    return res;
}
