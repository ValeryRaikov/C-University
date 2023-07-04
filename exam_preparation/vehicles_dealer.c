#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char vehicle_brand[15];
    char fuel_type[15];
    int hp;
    int year;
    int mileage;
    float price;
} Vehicle;

//Function to create a vehicle from the console:
Vehicle create_vehicle();

//Function to find a vehicle by brand:
void search_by_brand(Vehicle *vehicles_arr, int arr_len, char brand[]);


int main()
{
    int total_cars;
    printf("Enter the number of cars to store: ");
    scanf("%d", &total_cars);

    Vehicle *vehicles_arr = (Vehicle*)malloc(total_cars * sizeof(Vehicle));
    if (vehicles_arr == NULL)
    {
        perror("Dynamic memory error!");
        exit(1);
    }

    FILE *fptr_t = fopen("Vehicles_info.txt", "w");
    if (fptr_t == NULL)
    {
        perror("Error opening txt file!");
        exit(1);
    }

    FILE *fptr_b = fopen("Vehicles_info.bin", "wb");
    if (fptr_b == NULL)
    {
        perror("Error opening bin file");
        exit(1);
    }

    //Store information in a text/bin file:
    for (int i=0; i<total_cars; ++i)
    {
        vehicles_arr[i] = create_vehicle();
        if (fprintf(fptr_t, "(%d)Vehicle: %sFuel type: %sHP: %d\nYear: %d\nMileage: %d\nPrice: %.2f\n\n", i+1, vehicles_arr[i].vehicle_brand, vehicles_arr[i].fuel_type, vehicles_arr[i].hp, vehicles_arr[i].year, vehicles_arr[i].mileage, vehicles_arr[i].price)<0)
        {
            perror("Writing error!");
            exit(1);
        }
    }

    fclose(fptr_t);

    //Read information from the file:
    fptr_t = fopen("Vehicles_info.txt", "r");
    if (fptr_t == NULL)
    {
        perror("Error opening txt file!");
        exit(1);
    }

    fseek(fptr_t,0, SEEK_END);
    int length = ftell(fptr_t);
    fseek(fptr_t, 0, SEEK_SET);

    char *buffer = malloc(sizeof(char) * length + 1);
    while (fread(buffer, sizeof(buffer), 1, fptr_t)==1)
        printf("%s", buffer);

    fclose(fptr_t);

    char brand[15];
    printf("Enter car brand/model to search for: ");
    fflush(stdin);
    if (fgets(brand, sizeof(brand), stdin)==NULL)
    {
        perror("Input error!");
        exit(1);
    }
    fflush(stdin);
    search_by_brand(vehicles_arr, total_cars, brand);

    free(buffer);
    free(vehicles_arr);

    return 0;
}


Vehicle create_vehicle()
{
    Vehicle car1;

    fflush(stdin);
    printf("Enter vehicle brand/model: ");
    if (fgets(car1.vehicle_brand, sizeof(car1.vehicle_brand), stdin)==NULL)
    {
        perror("Input error!");
        exit(1);
    }
    fflush(stdin);
    printf("Enter vehicle fuel type: ");
    if (fgets(car1.fuel_type, sizeof(car1.fuel_type), stdin)==NULL)
    {
        perror("Input error!");
        exit(1);
    }
    fflush(stdin);
    printf("Enter HP: ");
    scanf("%d", &car1.hp);
    printf("Enter year of production: ");
    scanf("%d", &car1.year);
    printf("Enter current mileage: ");
    scanf("%d", &car1.mileage);
    printf("Enter price: ");
    scanf("%f", &car1.price);

    return car1;
}


void search_by_brand(Vehicle *vehicles_arr, int arr_len, char brand[])
{
    int flag = 0;
    for (int i=0; i<arr_len; ++i)
    {
        if (vehicles_arr[i].vehicle_brand == brand)
        {
            printf("(%d)Vehicle: %sFuel type: %sHP: %d\nYear: %d\nMileage: %d\nPrice: %.2f\n", i+1, vehicles_arr[i].vehicle_brand, vehicles_arr[i].fuel_type, vehicles_arr[i].hp, vehicles_arr[i].year, vehicles_arr[i].mileage, vehicles_arr[i].price);
        }
    }
    if (!flag)
        printf("No cars of this brand/model!\n");
}
