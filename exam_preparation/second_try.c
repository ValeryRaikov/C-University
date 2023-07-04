#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[32];
    char chip[8];
    float price;

} Animal;

int check_chip_code(char chip[]);

Animal create_animal()
{
    Animal an1;
    printf("Enter name: ");
    getchar();
    fgets(an1.name, sizeof(an1.name), stdin);
    printf("Enter chip code: ");
    do
    {
       scanf("%s", &an1.chip);
    } while (check_chip_code(an1.chip)!=0);
    printf("Enter price: ");
    do
    {
        scanf("%f", &an1.price);
    } while (an1.price < 0);

    FILE *fptr = fopen("animalsText.txt", "a");
    if (fptr == NULL)
    {
        perror("Error opening the file!");
        fclose(fptr);
        exit(1);
    }

    if (fprintf(fptr, "%s,%.2f", an1.name, an1.price)<0)
    {
        perror("Error writing in file!");
        fclose(fptr);
        exit(1);
    }

    return an1;
}

void animal_price_comp(Animal *animal_arr, int arr_length, float price)
{
    int flag = 0;
    for (int i=0; i<arr_length; ++i)
    {
        if (animal_arr[i].price == price)
        {
            flag = 1;
            printf("%s - %s", animal_arr[i].name, animal_arr[i].chip);
        }
    }
    if (!flag)
        printf("No such price in the database!");
}

void read_from_binary_file(float price)
{
    FILE *binptr = fopen("animalsBin.bin", "rb");
    if (binptr == NULL)
    {
        perror("Error opening the binary file!");
        fclose(binptr);
        exit(1);
    }
    Animal buffer;
    while (fread(&buffer, sizeof(Animal), 1, binptr)==1)
    {
        if (buffer.price >= price)
        {
            printf("Bin Owner Name: %s\n", buffer.name);
            printf("Bin Code: %s\n", buffer.chip);
            printf("Bin Price: %.2f\n", buffer.price);
        }
    }

    fclose(binptr);
}

int main()
{
    int number_of_animals;
    printf("Enter the number of animals you want to store: ");
    do
    {
        scanf("%d", &number_of_animals);
    } while (number_of_animals <= 0);

    Animal *animal_arr = (Animal*)malloc(number_of_animals * sizeof(Animal));
    if (animal_arr == NULL)
    {
        perror("Dynamic memory error!");
        exit(1);
    }

    FILE *fptr = fopen("animalsText.txt", "w");
    if (fptr == NULL)
    {
        perror("Error opening the file!");
        fclose(fptr);
        exit(1);
    }

    for (int i=0; i<number_of_animals; ++i)
        animal_arr[i] = create_animal();

    animal_price_comp(animal_arr, number_of_animals, 50);
    read_from_binary_file(10);

    fclose(fptr);
    free(animal_arr);

    return 0;
}

int check_chip_code(char chip[])
{
    if (chip[0] < 'A' || chip[0] > 'Z')
    {
        printf("Error in chip code. Try again: ");
        return 1;
    }

    for (int i=1; i<6; ++i)
    {
        if (chip[i] < '0' || chip[i] > '9')
        {
            printf("Error in chip code. Try again: ");
            return 1;
        }
    }

    if (chip[6] < 'A' || chip[6] > 'Z')
    {
        printf("Error in chip code. Try again: ");
        return 1;
    }

    return 0;
}
