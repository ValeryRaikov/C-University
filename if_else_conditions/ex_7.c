#include <stdio.h>

float min(float, float, float);

int main()
{
    float taxi_start_price = 0.70;
    float taxi_price_day = 0.79, taxi_price_night = 0.90;
    float bus_price = 0.09;
    float train_price = 0.06;

    int km;
    char period;
    printf("Enter kilometers:\n");
    scanf("%d", &km);

    float total_price;
    if (km < 20)
    {
        printf("Enter period:\n");
        scanf(" %c", &period);
        if (period=='D')
            total_price = km*taxi_price_day+taxi_start_price;
        else
            total_price = km*taxi_price_night+taxi_start_price;
    } else if (km >= 20 && km < 100)
    {
        total_price = km*bus_price;
    } else
    {
        total_price = min(km*taxi_price_day+taxi_start_price, km*bus_price, km*train_price);
    }
    printf("Total price is %.2f leva", total_price);

    return 0;
}

float min(float a, float b, float c)
{
    if (a<b && a<c)
        return a;
    else if (b<a && b<c)
        return b;
    else
        return c;
}
