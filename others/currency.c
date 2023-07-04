#include <stdio.h>

int main()
{
    double leva, dollars, euros, pounds;
    printf("Enter leva: ");
    scanf("%lf", &leva);

    dollars = leva * 0.54;
    euros = leva * 0.51;
    pounds = leva * 44;

    return 0;
}
