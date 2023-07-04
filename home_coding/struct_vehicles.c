#include <stdio.h>
#include <string.h>

void print_car(Vehicle);
void compare_cars(Vehicle, Vehicle);

typedef struct
{
    char brand[20];
    char model[20];
    int year;
    int mileage;
    int price;
}Vehicle;

int main()
{
    Vehicle first;

    char brand[20], model[20];
    int year, mileage, price;
    printf("Enter brand and model:\n");
    scanf("%s %s", &brand, &model);
    printf("Enter year of production:\n");
    scanf("%d", &year);
    printf("Enter mileage:\n");
    scanf("%d", &mileage);
    printf("Enter price:\n");
    scanf("%d", &price);

    strcpy(first.brand, brand);
    strcpy(first.model, model);
    first.year = year;
    first.mileage = mileage;
    first.price = price;

    print_car(first);

    Vehicle second;

    char brand2[20], model2[20];
    int year2, mileage2, price2;
    printf("Enter brand and model:\n");
    scanf("%s %s", &brand, &model);
    printf("Enter year of production:\n");
    scanf("%d", &year);
    printf("Enter mileage:\n");
    scanf("%d", &mileage);
    printf("Enter price:\n");
    scanf("%d", &price);

    strcpy(second.brand, brand);
    strcpy(second.model, model);
    second.year = year;
    second.mileage = mileage;
    second.price = price;

    print_car(second);

    compare_cars(first, second);

    return 0;
}

void print_car(Vehicle car)
{
    printf("Car information:\n");
    printf("Brand -> %s\nModel -> %s\nYear -> %d\nMileage -> %d\nPrice -> %d\n", car.brand, car.model, car.year, car.mileage, car.price);
}

void compare_cars(Vehicle car1, Vehicle car2)
{
    printf("Comparison summary:\n");

    int count_car1, count_car2;

    if(car1.year > car2.year)
    {
        int diff = car1.year - car2.year;
        printf("%s %s is newer. Difference in years is %d\n", car1.brand, car1.model, diff);
        count_car1++;
    }
    else if(car2.year > car1.year)
    {
        int diff = car2.year - car1.year;
        printf("%s %s is newer. Difference in years is %d\n", car2.brand, car2.model, diff);
        count_car2++;
    }
    else
        printf("Both cars are produced in the same year!\n");

    if(car1.mileage < car2.mileage)
    {
        int diff = car2.mileage - car1.mileage;
        printf("%s %s is less driven. Difference in mileages is %d\n", car1.brand, car1.model, diff);
        count_car1++;
    }
    else if(car2.mileage < car1.mileage)
    {
        int diff = car1.mileage - car2.mileage;
        printf("%s %s is less driven. Difference in mileages is %d\n", car2.brand, car2.model, diff);
        count_car2++;
    }
    else
        printf("Both cars are driven the same amount of kilometers!\n");

     if(car1.price < car2.price)
    {
        int diff = car2.price - car1.price;
        printf("%s %s is cheaper. Difference in prices is %d\n", car1.brand, car1.model, diff);
        count_car1++;
    }
    else if(car2.price < car1.price)
    {
        int diff = car1.price - car2.price;
        printf("%s %s is less driven. Difference in prices is %d\n", car2.brand, car2.model, diff);
        count_car2++;
    }
    else
        printf("Both cars cost the same!\n");

    putchar('\n');

    if(count_car1 == count_car2)
        printf("No winner!");
    else
        (count_car1 > count_car2) ? printf("%s %s is the better choice!\n", car1.brand, car1.model) : printf("%s %s is the better choice!\n", car2.brand, car2.model);
}
