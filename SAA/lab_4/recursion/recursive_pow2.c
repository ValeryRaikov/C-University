#include <stdio.h>

double power(double x, int n) {
    if (n > 0)
        return x * power(x, n - 1);
    else if (n == 0)
        return 1;
    else
        return 1.0 / power(x, -n);
}

int main() {
    double x;
    int n;

    printf("Enter the base (x): ");
    scanf("%lf", &x);
    printf("Enter the exponent (n): ");
    scanf("%d", &n);

    double result = power(x, n);
    printf("%.2lf^%d = %.3lf\n", x, n, result);

    return 0;
}

