#include <stdio.h>
#include <string.h>

typedef struct
{
    char brand[15];
    char model[15];
    char fuel_type[10];
    int year;
    int mileage;
    int hp;
    int price;
} Vehicles;

void print_struct(Vehicles vehicle);

int main()
{
    Vehicles first_vehicle, second_vehicle;

    strcpy(first_vehicle.brand, "Skoda");
    strcpy(first_vehicle.model, "Octavia");
    strcpy(first_vehicle.fuel_type, "diesel");
    first_vehicle.year = 2015;
    first_vehicle.mileage = 150000;
    first_vehicle.hp = 150;
    first_vehicle.price = 20000;

    printf("%s %s:\nFuel type: %s\nYear: %d\nMileage: %d\nHP: %d\nPrice: %d\n", first_vehicle.brand, first_vehicle.model, first_vehicle.fuel_type, first_vehicle.year, first_vehicle.mileage, first_vehicle.hp, first_vehicle.price);

    //test the function:
    print_struct(second_vehicle);

    return 0;
}

void print_struct(Vehicles vehicle)
{
    printf("Enter vehicle information:\n");
    char brand[15], model[15], fuel_type[10];
    scanf("%s", &brand);
    scanf("%s", &model);
    scanf("%s", &fuel_type);

    strcpy(vehicle.brand, brand);
    strcpy(vehicle.model, model);
    strcpy(vehicle.fuel_type, fuel_type);
    scanf("%d", &vehicle.year);
    scanf("%d", &vehicle.mileage);
    scanf("%d", &vehicle.hp);
    scanf("%d", &vehicle.price);

    printf("%s %s:\nFuel type: %s\nYear: %d\nMileage: %d\nHP: %d\nPrice: %d", vehicle.brand, vehicle.model, vehicle.fuel_type, vehicle.year, vehicle.mileage, vehicle.hp, vehicle.price);
}
