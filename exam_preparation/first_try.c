#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    char owner_name[32];
    char code[9];
    float price;

} Animal;

Animal get_info_from_user()
{
    Animal ptr;

    printf("Enter owner name: ");
    fgets(ptr.owner_name, sizeof(ptr.owner_name), stdin);
    ptr.owner_name[strlen(ptr.owner_name)-1]=='\0';

    int flag = 0;

    printf("Enter code: ");
    while (!flag)
    {
        scanf("%s", ptr.code);
        if (ptr.code[0] < 'A' || ptr.code[0] > 'Z')
        {
            printf("Wrong code. Try again: ");
            continue;
        }

        for (int i=1; i<6; ++i)
        {
            if (ptr.code[i] < '0' || ptr.code[i] > '9')
                printf("Wrong code. Try again: ");
                continue;
        }

        if (ptr.code[6] < 'A' || ptr.code[6] > 'Z')
        {
            printf("Wrong code. Try again: ");
            continue;
        }

        flag = 1;
    }

    printf("Enter price: ");
    scanf("%f", &ptr.price);

    FILE *txt_ptr;
    if ((txt_ptr=fopen("animals.txt", "w"))==NULL)
    {
        perror("Error occurred!\n");
        exit(EXIT_FAILURE);
    }
    if (fprintf(txt_ptr, "%s, &.2f\n", ptr.owner_name, ptr.price)<0)
    {
        printf("Error writing in file!\n");
        fclose(txt_ptr);
        exit(EXIT_FAILURE);
    }
    fclose(txt_ptr);

    return ptr;
}

void check_owner_existance(Animal *animals, int arr_length, float price)
{
    int flag = 0;
    for (int i=0; i<arr_length; ++i)
    {
        if (animals[i].price == price)
        {
            printf("%s - %s", animals[i].owner_name, animals[i].code);
            flag = 1;
        }

        if (!flag)
            printf("No such person!\n");
    }
}

void bin_read_animal(float price)
{
    FILE *bin_ptr;
    if ((bin_ptr=fopen("animalsBin.bin", "rb"))==NULL)
    {
        perror("Error occurred!\n");
        exit(EXIT_FAILURE);
    }
    Animal buff;
    while (fread(&buff, sizeof(Animal), 1, bin_ptr)==1)
    {
        if (buff.price >= price)
        {
            printf("Bin Owner Name: %s\n", buff.owner_name);
            printf("Bin Code: %s\n", buff.code);
            printf("Bin Price: %.2f\n", buff.price);
        }
    }
    fclose(bin_ptr);
}

int main()
{
    Animal * animal_arr = (Animal*)malloc(sizeof(Animal));
    if (animal_arr == NULL)
    {
        perror("Error occurred!\n");
        exit(EXIT_FAILURE);
    }

    FILE *f_ptr;
    if ((f_ptr = fopen("animalsText.txt", "w"))==NULL)
    {
        perror("Error occurred!\n");
        exit(EXIT_FAILURE);
    }
    fclose(f_ptr);

    animal_arr[0] = get_info_from_user();

    check_owner_existance(animal_arr, 1, 10);

    bin_read_animal(10);

    free(animal_arr);

    return 0;
}
