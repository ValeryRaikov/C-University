#include <stdio.h>
#include <string.h>

typedef struct
{
    char brand[20];
    char model[20];
    int year;
    int mileage;
    int price;
} Vehicle;

typedef struct
{
    int hp;
    char fuel_type[10];
    Vehicle vehicle_info;
} Car;

typedef struct
{
    int max_speed;
    char brake_type[15];
    Vehicle vehicle_info;
} Motorcycle;

typedef struct
{
    int fuel_capacity;
    int passanger_capacity;
    Vehicle vehicle_info;
} Plane;

typedef struct
{
    int length;
    int size;
    Vehicle vehicle_info;
} Boat;

int main()
{
    Car car1;

    strcpy(car1.vehicle_info.brand, "Skoda");
    strcpy(car1.vehicle_info.model, "Octavia");
    car1.vehicle_info.year = 2015;
    car1.vehicle_info.mileage = 150000;
    car1.vehicle_info.price = 18000;
    car1.hp = 150;
    strcpy(car1.fuel_type, "diesel");


    Motorcycle motor1;

    strcpy(motor1.vehicle_info.brand, "Kawasaki");
    strcpy(motor1.vehicle_info.model, "Integra");
    motor1.vehicle_info.year = 2017;
    motor1.vehicle_info.mileage = 20000;
    motor1.vehicle_info.price = 15000;
    motor1.max_speed = 280;
    strcpy(motor1.brake_type, "direct");

    Plane plane1;

    strcpy(plane1.vehicle_info.brand, "Airbus");
    strcpy(plane1.vehicle_info.model, "MX123");
    plane1.vehicle_info.year = 2009;
    plane1.vehicle_info.mileage = 1050000;
    plane1.vehicle_info.price = 10000000;
    plane1.fuel_capacity = 15000;
    plane1.passanger_capacity = 220;

    Boat boat1;

    strcpy(boat1.vehicle_info.brand, "Titanic");
    strcpy(boat1.vehicle_info.model, "Titanski");
    boat1.vehicle_info.year = 1995;
    boat1.vehicle_info.mileage = 100000;
    boat1.vehicle_info.price = 1000000;
    boat1.length = 80;
    boat1.size = 250;

    compare_vehicles(car1, motor1, plane1, boat1);

    return 0;
}

void compare_vehicles(Car car, Motorcycle motor, Plane plane, Boat boat)
{
    printf("Comparison summary:\n");
    if(car.vehicle_info.year > motor.vehicle_info.year)
    {
        int diff = car.vehicle_info.year - motor.vehicle_info.year;
        printf("%s %s is newer. Difference in years is %d\n", car.vehicle_info.brand, car.vehicle_info.model, diff);
    }
    else
    {
        int diff = motor.vehicle_info.year - car.vehicle_info.year;
        printf("%s %s is newer. Difference in years is %d\n", motor.vehicle_info.brand, motor.vehicle_info.model, diff);
    }

    if(plane.vehicle_info.price > boat.vehicle_info.price)
    {
        int diff = plane.vehicle_info.price - boat.vehicle_info.price;
        printf("%s %s is more expenive. Difference in price is %d\n", plane.vehicle_info.brand, plane.vehicle_info.model, diff);
    }
    else
    {
        int diff = boat.vehicle_info.price- plane.vehicle_info.price;
        printf("%s %s is more expensive. Difference in price is %d\n", boat.vehicle_info.brand, boat.vehicle_info.model, diff);
    }
}
