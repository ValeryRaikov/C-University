#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c, A, B, C, P;

    printf("a = ");
    scanf("%lf", &a);
    printf("b = ");
    scanf("%lf", &b);
    printf("c = ");
    scanf("%lf", &c);
    printf("A (angle/rad) = : ");
    scanf("%lf", &A);

    B = asin((b * sin(A)) / a);
    C = asin((c * sin(A)) / a);

    P = a + b + c;

    printf("Triangle perimeter is: %lf\n", P);

    return 0;
}

