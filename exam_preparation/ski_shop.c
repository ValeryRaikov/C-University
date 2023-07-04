#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char ski_brand[15];
    char ski_model[15];
    int size;
    int year;
    float price;
} Ski;

Ski create_ski_set()
{
    Ski ski_set;

    printf("Enter ski brand: ");
    if (fgets(ski_set.ski_brand, sizeof(ski_set.ski_brand), stdin)==NULL)
    {
        perror("Input error!");
        exit(1);
    }
    ski_set.ski_brand[strlen(ski_set.ski_brand)-1]='0';
    printf("Enter ski model: ");
    if (fgets(ski_set.ski_model, sizeof(ski_set.ski_model), stdin)==NULL)
    {
        perror("Input error!");
        exit(1);
    }
    ski_set.ski_model[strlen(ski_set.ski_model)-1]='\0';

    printf("Enter size: ");
    do
    {
        scanf("%d", &ski_set.size);
    } while (ski_set.size <= 70);

    printf("Enter year: ");
    do
    {
        scanf("%d", &ski_set.year);
    } while (ski_set.year <= 2017);

    printf("Enter price: ");
    do
    {
        scanf("%f", &ski_set.price);
    } while (ski_set.price <= 0);

    FILE *fptr = fopen("ski_database.txt", "w");
    if (fptr == NULL)
    {
        perror("Error opening file!");
        exit(1);
    }

    if (fprintf(fptr, "%s %s, size: %d, year: %d, price: %.2f\n", ski_set.ski_brand, ski_set.ski_model, ski_set.size, ski_set.year, ski_set.price)<0)
    {
        perror("Error writing in file!");
        exit(1);
    }
    fclose(fptr);

    return ski_set;
}

void check_ski_in_stock(Ski *ski_array, int arr_len, char brand[], char model[])
{
    int flag = 0;
    for (int i=0; i<arr_len; ++i)
    {
        if (ski_array[i].ski_brand == brand && ski_array[i].ski_model == model)
        {
            printf("%s %s, size: %d, year: %d, price: %.2f\n", ski_array[i].ski_brand, ski_array[i].ski_model, ski_array[i].size, ski_array[i].year, ski_array[i].price);
        }
    }
    if (!flag)
        printf("Ski not found!\n");
}

int main()
{
    int items;
    printf("Enter the number of ski items you want to enter: ");
    do
    {
        scanf("%d", &items);
    } while (items <= 0);

    Ski *ski_array = (Ski*)malloc(items * sizeof(Ski));

    for (int i=0; i<items; ++i)
        ski_array[i] = create_ski_set();

    check_ski_in_stock(ski_array, items, "Atomic", "Redster");

    free(ski_array);

    return 0;
}
