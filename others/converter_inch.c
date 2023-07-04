#include <stdio.h>

int main()
{
    double inches;
    printf("Enter inches: ");
    scanf("%lf", &inches);

    double mm, cm, dm, m;

    mm = inches * 25.4;
    cm = inches * 2.54;
    dm = inches / 3.937;
    m = inches / 39.37;

    printf("The value of %.2lf inches is %.2lf mm, %.2lf cm, %.2lf dm, %.2lf m", inches, mm, cm, dm, m);

    return 0;
}
