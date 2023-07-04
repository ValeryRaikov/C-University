#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MODELS 100

typedef struct {
    char make[5];
    char model[6];
    float engine_capacity;
    float price;
    char registration;
} car;

void write_text_file(car cars[], int num_cars);
void write_binary_file(car cars[], int num_cars);
void add_car(car cars[], int *num_cars);
void read_files();

int main() {
    car cars[MAX_MODELS];
    int num_cars = 0;

    add_car(cars, &num_cars);
    add_car(cars, &num_cars);
    add_car(cars, &num_cars);

    write_text_file(cars, num_cars);
    write_binary_file(cars, num_cars);

    read_files();

    return 0;
}

void write_text_file(car cars[], int num_cars) {
    FILE *file = fopen("car_database.txt", "w");

    for (int i = 0; i < num_cars; i++) {
        fprintf(file, "%s %s %.2f %.2f %c\n", cars[i].make, cars[i].model, cars[i].engine_capacity, cars[i].price, cars[i].registration);
    }

    fclose(file);
}

void write_binary_file(car cars[], int num_cars) {
    FILE *file = fopen("car_database.bin", "wb");

    fwrite(&num_cars, sizeof(int), 1, file);

    for (int i = 0; i < num_cars; i++) {
        fwrite(&cars[i], sizeof(car), 1, file);
    }

    fclose(file);
}

void add_car(car cars[], int *num_cars) {
    printf("Enter car make: ");
    scanf("%s", cars[*num_cars].make);

    printf("Enter car model (5 characters): ");
    scanf("%s", cars[*num_cars].model);

    printf("Enter engine capacity: ");
    scanf("%f", &cars[*num_cars].engine_capacity);

    printf("Enter price: ");
    scanf("%f", &cars[*num_cars].price);

    printf("Enter registration (Y/N): ");
    scanf(" %c", &cars[*num_cars].registration);

    (*num_cars)++;
}

void read_files() {
    FILE *text_file = fopen("car_database.txt", "r");
    FILE *binary_file = fopen("car_database.bin", "rb");

    if (text_file == NULL || binary_file == NULL) {
        printf("Failed to open files.\n");
        exit(1);
    }

    int num_cars;
    fread(&num_cars, sizeof(int), 1, binary_file);

    printf("Car database from text file:\n");
    char line[100];
    while (fgets(line, 100, text_file) != NULL) {
        printf("%s", line);
    }

    printf("\nCar database from binary file:\n");
    for (int i = 0; i < num_cars; i++) {
        car current_car;
        fread(&current_car, sizeof(car), 1, binary_file);
        printf("%s %s %.2f %.2f %c\n", current_car.make, current_car.model, current_car.engine_capacity, current_car.price, current_car.registration);
    }

    fclose(text_file);
    fclose(binary_file);
}
