#include <stdio.h>

int main()
{
    int age = 25;
    (age > 18) ? printf("Old enough to vote.\n") : printf("Not old enough to vote.\n");

    int day;
    printf("Enter number of day:\n");
    scanf("%d", &day);
    (day>0 && day<6) ? printf("Weekday\n") : printf("Not a weekday.\n");

    return 0;
}
