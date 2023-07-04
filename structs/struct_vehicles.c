#include <stdio.h>
#include <string.h>

void print_car(Car);

typedef struct
{
    char brand[20];
    char model[20];
    int year;
    int mileage;
    int price;
} Car;

typedef struct
{
    char brand[20];
    char model[20];
    int year;
    int mileage;
    int price;
} Motorcycle;

int main()
{
    Car car1;

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

    strcpy(car1.brand, brand);
    strcpy(car1.model, model);
    car1.year = year;
    car1.mileage = mileage;
    car1.price = price;

    print_car(car1);

    Motorcycle motor1;

    char brand2[20], model2[20];
    int year2, mileage2, price2;
    printf("Enter brand and model:\n");
    scanf("%s %s", &brand2, &model2);
    printf("Enter year of production:\n");
    scanf("%d", &year2);
    printf("Enter mileage:\n");
    scanf("%d", &mileage2);
    printf("Enter price:\n");
    scanf("%d", &price2);

    strcpy(motor1.brand, brand2);
    strcpy(motor1.model, model2);
    motor1.year = year2;
    motor1.mileage = mileage2;
    motor1.price = price2;

    print_motor(motor1);

    compare_vehicles(car1, motor1);

    return 0;
}

void print_car(Car car)
{
    printf("Car information:\n");
    printf("Brand -> %s\nModel -> %s\nYear -> %d\nMileage -> %d\nPrice -> %d\n", car.brand, car.model, car.year, car.mileage, car.price);
}

void print_motor(Motorcycle motor)
{
    printf("Motorcycle information:\n");
    printf("Brand -> %s\nModel -> %s\nYear -> %d\nMileage -> %d\nPrice -> %d\n", motor.brand, motor.model, motor.year, motor.mileage, motor.price);
}

void compare_vehicles(Car car, Motorcycle motor)
{
    printf("Comparison summary:\n");

    int count_car, count_motor;

    if(car.year > motor.year)
    {
        int diff = car.year - motor.year;
        printf("%s %s is newer. Difference in years is %d\n", car.brand, car.model, diff);
        count_car++;
    }
    else if(motor.year > car.year)
    {
        int diff = motor.year - car.year;
        printf("%s %s is newer. Difference in years is %d\n", motor.brand, motor.model, diff);
        count_motor++;
    }
    else
        printf("Both vehicles are produced in the same year!\n");

    if(car.mileage < motor.mileage)
    {
        int diff = motor.mileage - car.mileage;
        printf("%s %s is less driven. Difference in mileages is %d\n", car.brand, car.model, diff);
        count_car++;
    }
    else if(motor.mileage < car.mileage)
    {
        int diff = car.mileage - motor.mileage;
        printf("%s %s is less driven. Difference in mileages is %d\n", motor.brand, motor.model, diff);
        count_motor++;
    }
    else
        printf("Both vehicles are driven the same amount of kilometers!\n");

     if(car.price < motor.price)
    {
        int diff = motor.price - car.price;
        printf("%s %s is cheaper. Difference in prices is %d\n", motor.brand, motor.model, diff);
        count_car++;
    }
    else if(motor.price < car.price)
    {
        int diff = car.price - motor.price;
        printf("%s %s is less driven. Difference in prices is %d\n", motor.brand, motor.model, diff);
        count_motor++;
    }
    else
        printf("Both vehicles cost the same!\n");

    putchar('\n');

    if(count_car == count_motor)
        printf("No winner!");
    else
        (count_car > count_motor) ? printf("%s %s is the better choice!\n", car.brand, car.model) : printf("%s %s is the better choice!\n", motor.brand, motor.model);
}

