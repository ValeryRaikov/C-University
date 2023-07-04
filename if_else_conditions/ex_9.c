#include <stdio.h>

int main()
{
    int length, width, area;
    printf("Enter the yard values:\n");
    scanf("%d %d", &length, &width);
    area = length * width;
    printf("Area = %d\n", area);

    float percents = 0.40;
    float area_for_wine = area * percents;
    printf("Wine area = %.2f\n", area_for_wine);

    int kg_grapes;
    printf("Enter grapes kg:\n");
    scanf("%d", &kg_grapes);

    float total_grapes = kg_grapes * area_for_wine;
    float total_wine = total_grapes / 2.5;

    int wine_for_sell;
    printf("Enter quantity to sell:\n");
    scanf("%d", &wine_for_sell);

    float diff;
    if (wine_for_sell>total_wine)
    {
        diff = wine_for_sell - total_wine;
        printf("Not enough wine. %.2f liers insuficient.\n", diff);
    } else
    {
        diff = total_wine - wine_for_sell;
        printf("Enough wine! %.2f liters left.\n", diff);
        int workers;
        printf("Enter workers number:\n");
        scanf("%d", &workers);
        float liters_per_worker = diff / workers;
        printf("%.2f liters per worker", liters_per_worker);
    }

    return 0;
}
