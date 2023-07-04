#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    unsigned vehicle_number;
    char brand[30];
    char registration[9];
} Car;

Car create_car();
bool check_registration(char registration[]);

int main()
{
    int total_cars;
    printf("Enter number of cars to store: ");
    scanf("%d", &total_cars);

    Car *car_arr = (Car*)malloc(total_cars * sizeof(Car));

    for (int i=0; i<total_cars; ++i)
    {
        car_arr[i] = create_car();
    }

    return 0;
}

Car create_car()
{
    Car car;

    printf("Enter car number: ");
    scanf("%d", &car.vehicle_number);
    printf("Enter car brand: ");
    fflush(stdin);
    fgets(car.brand, sizeof(car.brand), stdin);
    fflush(stdin);
    do
    {
        printf("Enter car registration: ");
        scanf("%s", car.registration);
    } while (!check_registration(car.registration));
}

bool check_registration(char regitration[])
{
    bool isValid = true;
    for (int i=0; i<2; ++i)
    {
        if (regitration[i] < 'A' || regitration[i] > 'Z')
        {
            printf("Registration error.\n");
            isValid = false;
        }
    }
    for (int i=2; i<6; ++i)
    {
        if (regitration[i] < '0' || regitration[i] > '9')
        {
            printf("Registration error.\n");
            isValid = false;
        }
    }
    for (int i=6; i<8; ++i)
    {
        if (regitration[i] < 'A' || regitration[i] > 'Z')
        {
            perror("Registration error.\n");
            isValid = false;
        }
    }

    return isValid;
}
