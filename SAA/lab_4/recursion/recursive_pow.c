#include <stdio.h>

double n_pow(double num, int pow) {
    if (num == 0 && pow == 0)
        return 1;
    else if (num == 0)
        return 0;
    else if (pow == 0)
        return 1;
    else {
        if (pow > 1)
            return num * n_pow(num, pow-1);
        else
            return 1.0 / n_pow(num, -pow);
    }
}

int main() {
    double number;
    int power;

    printf("Enter a number: ");
    scanf("%lf", &number);
    printf("Enter a power: ");
    scanf("%d" , &power);

    double result = n_pow(number, power);
    printf("%.2lf on power of %d is %.3lf", number, power, result);

    return 0;
}
