#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    char unique_id[3];
    char product_name[22];
    int weight;
    float price_per_kg;
} IceCream;

bool check_id(char id[])
{
    if (id[0] < 'A' || id[0] > 'Z')
    {
        printf("Input error!\n");
        return false;
    }
    if (id[1] < '0' || id[1] > '9')
    {
        printf("Input error!\n");
        return false;
    }

    return true;
}

float calculate_price(IceCream *arr, int arr_len, char symbol);
int work_with_txt(IceCream *arr, int arr_len, float price, int weight);
void work_with_bin(char unique_id[]);

int main()
{
    int n;
    do
    {
        printf("Enter number of ice-creams: ");
        scanf("%d", &n);
    } while (n < 5 || n > 15);

    IceCream *ice_arr = (IceCream*)malloc(n * sizeof(IceCream));
    if (ice_arr == NULL)
    {
        printf("Dynamic memory error!");
        exit(1);
    }

    for (int i=0; i<n; ++i)
    {
        do
        {
            printf("Enter unique id: ");
            scanf("%s", &ice_arr[i].unique_id);
        } while (!check_id(ice_arr[i].unique_id));
        printf("Enter ice-cream name: ");
        fflush(stdin);
        if (fgets(ice_arr[i].product_name, sizeof(ice_arr[i].product_name), stdin)==NULL)
        {
            printf("Input error");
            exit(1);
        }
        ice_arr[i].product_name[strlen(ice_arr[i].product_name)-1] = '\0';
        fflush(stdin);
        printf("Enter weight: ");
        scanf("%d", &ice_arr[i].weight);
        printf("Enter price per kilogram: ");
        scanf("%f", &ice_arr[i].price_per_kg);
    }

    float test_func1 = calculate_price(ice_arr, n, 'c');
    printf("Total price: %.2f\n", test_func1);

    int test_func2 = work_with_txt(ice_arr, n, 10, 3);
    printf("Total matches: %d\n", test_func2);

    work_with_bin("A5");

    free(ice_arr);

    return 0;
}

float calculate_price(IceCream *arr, int arr_len, char symbol)
{
    bool isFound = false;
    float total_price = 0;
    for (int i=0; i<arr_len; ++i)
    {
        if (arr[i].product_name[0] == symbol)
        {
            isFound = true;
            total_price += arr[i].price_per_kg * arr[i].weight;
        }
    }
    if (isFound)
        return total_price;
    else
        return 0;
}

int work_with_txt(IceCream *arr, int arr_len, float price, int weight)
{
    FILE *fptr = fopen("info_2.txt", "w");
    if (fptr == NULL)
    {
        printf("Error opening file!");
        exit(1);
    }

    int counter = 0;
    for (int i=0; i<arr_len; ++i)
    {
        if (arr[i].price_per_kg < price && arr[i].weight > weight)
        {
            counter++;
            if (fprintf(fptr, "%s;%s;%d;%.2fleva\n", arr[i].unique_id, arr[i].product_name, arr[i].weight, arr[i].price_per_kg)<0)
            {
                printf("Writing error!");
                exit(1);
            }
        }
    }
    fclose(fptr);

    return counter;
}

void work_with_bin(char unique_id[])
{
    FILE *fptr = fopen("icecream.bin", "rb");
    if (fptr == NULL)
    {
        printf("Error opening file!");
        exit(1);
    }

    IceCream buff;
    bool isFound = false;
    while (fread(&buff, sizeof(IceCream), 1, fptr)==1)
    {
        if (strcmp(buff.unique_id, unique_id)==0)
        {
            isFound = true;
            printf("IceCream - %s\n", buff.product_name);
            printf("Price - %.2f BGN\n", buff.price_per_kg);
            puts("====================\n");
        }
    }
    if (!isFound)
        printf("No data!\n");

    fclose(fptr);
}
