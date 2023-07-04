#include <stdio.h>

float square(float);
float rectangular(float, float);
float triangle(float, float);
float circle(float);
float metrics_a();
float metrics_b();

void main()
{
    int number;
    printf("Enter number:\n");
    scanf("%d", &number);

    float result;
    switch (number)
    {
    case 1:
        printf("Figure is a square\n");
        result = square(metrics_a());
        printf("%.2f", result);
        break;
    case 2:
        printf("Figure is a rectangular\n");
        result = rectangular(metrics_a(), metrics_b());
        printf("%.2f", result);
        break;
    case 3:
        printf("Figure is a triangle\n");
        result = triangle(metrics_a(), metrics_b());
        printf("%.2f", result);
        break;
    case 4:
        printf("Figure is a circle\n");
        result = circle(metrics_a());
        printf("%.2f", result);
        break;
    default:
        printf("Wrong input!\n");
    }
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
float metrics_a()
{
    float a;
    printf("Enter value:\n");
    scanf("%f", &a);
    return a;
}
float metrics_b()
{
    float b;
    printf("Enter value:\n");
    scanf("%f", &b);
    return b;
}
