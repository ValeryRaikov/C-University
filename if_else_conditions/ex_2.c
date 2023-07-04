#include <stdio.h>

int main ()
{
    int hours, minutes, diff = 15;
    printf("Enter hours:\n");
    scanf("%d", &hours);
    printf("Enter minutes:\n");
    scanf("%d", &minutes);

    if (hours > 24 || minutes > 60)
        printf("Wrong input!");

    else if (hours == 24)
    {
        if (minutes >= 45)
        {
            minutes -= 60;
            minutes += 15;
            hours += 1;

        if (minutes < 10)
        {
            printf("01:0%d\n", minutes);
        } else
        {
            printf("01:%d\n", minutes);
        }
    }
    else
        printf("00:%d\n", minutes+diff);
        }

    else if (minutes >= 45)
    {
        minutes -= 60;
        minutes += 15;
        hours += 1;

        if (minutes < 10)
        {
            printf("%d:0%d\n", hours, minutes);
        } else
        {
            printf("%d:%d\n", hours, minutes);
        }
    }
    else
        printf("%d:%d\n", hours, minutes+diff);

    return 0;
}
