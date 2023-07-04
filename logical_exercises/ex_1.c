#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main()
{
    float chair=13.99, table=42.00, pack_cups=5.98, pack_utensils=21.02;

    int guests;
    printf("Enter number of guests:\n");
    scanf("%d", &guests);

    char purchase[20];

    float total_sum;
    int count_chairs=0, count_tables=0, count_cups=0, count_dishes=0;

    while(true)
    {
        printf("Enter purchase:\n");
        scanf("%s", &purchase);

        if(strcmp(purchase, "PARTY!")==0)
        {
            break;
        }

        if(strcmp(purchase, "Chair")==0)
        {
            total_sum += chair;
            count_chairs++;
        }
        else if(strcmp(purchase, "Table")==0)
        {
            total_sum += table;
            count_tables++;
        }
        else if(strcmp(purchase, "Cups")==0)
        {
            total_sum += pack_cups;
            count_cups++;
        }
        else if(strcmp(purchase, "Dishes")==0)
        {
            total_sum += pack_utensils;
            count_dishes++;
        }
        else
            printf("Wrong input!\n");
    }

    printf("Summary:\n");
    printf("Total guests: %d\n", guests);
    printf("Total money spent: %.2f lv\n", total_sum);
    printf("Products bought: %d chairs, %d tables, %d cups, %d dishes\n", count_chairs, count_tables, count_cups, count_dishes);

    if(guests>count_chairs)
        printf("%d more chairs needed!\n", guests-count_chairs);

    if (guests>count_tables*8)
        printf("%d more tables needed!\n", (guests-count_tables*8)/8+1);

    if(guests>count_cups*6)
        printf("%d more cups needed!\n", (guests-count_cups*6)/6+1);

    if(guests>count_dishes*6)
        printf("%d more dishes needed!\n", (guests-count_dishes*6)/6+1);

    return 0;
}
