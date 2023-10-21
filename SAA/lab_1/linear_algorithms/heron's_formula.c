#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    double p, area;

    printf("a = ");
    scanf("%lf", &a);
    printf("b = ");
    scanf("%lf", &b);
    printf("c = ");
    scanf("%lf", &c);

    p = (a + b + c) / 2;

    area = sqrt(p * (p - a) * (p - b) * (p - c));


    printf("The are is: %lf\n", area);

    return 0;
}

