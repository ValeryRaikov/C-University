#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    fp = fopen("cars_file_write.txt", "w");
    if (fp == NULL)
    {
        perror("Error opening the file.");
        exit(1);
    }

    char brand[20];
    char model[20];
    int year;
    float price;

    printf("Enter the information you want to write in file!\n");
    scanf("%s", &brand);
    scanf("%s", &model);
    scanf("%d", &year);
    scanf("%f", &price);

    if (fprintf(fp, "Car: %s %s, year: %d, price: %.2f", brand, model, year, price)<0)
    {
        perror("Error writing in file.");
        fclose(fp);
        exit(1);
    }
    fclose(fp);

    return 0;
}
