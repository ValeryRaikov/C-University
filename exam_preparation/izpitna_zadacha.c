#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
    char owner_name[32];
    char chip_code[8];
    float price;
} Patient;

bool check_patients_code(char code[])
{
    if (code[0] < 'A' || code[0] > 'Z')
    {
        printf("Error in code format! ");
        return false;
    }
    for (int i=1; i<6; ++i)
    {
        if (code[i] < '0' || code[i] > '9')
        {
            printf("Error in code format! ");
            return false;
        }
    }
    if (code[6] < 'A' || code[6] > 'Z')
    {
        printf("Error in code format! ");
        return false;
    }

    return true;
}

Patient create_new_patient()
{
    Patient p;

    printf("Enter owner name: ");
    fflush(stdin);
    if (fgets(p.owner_name, sizeof(p.owner_name), stdin)==NULL)
    {
        printf("Input error!");
        exit(1);
    }
    p.owner_name[strlen(p.owner_name)-1] = '\0';
    fflush(stdin);
    do
    {
        printf("Enter chip code: ");
        scanf("%s", &p.chip_code);
    } while (!check_patients_code(p.chip_code));
    printf("Enter price: ");
    scanf("%f", &p.price);

    FILE *fptr =fopen("PatientsText.txt", "a");
    if (fptr == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    if (fprintf(fptr, "%s,%.2f", p.owner_name, p.price)<0)
    {
        printf("Writing error! ");
        exit(1);
    }

    fclose(fptr);

    return p;
}

void search_function(Patient *arr, int arr_len, float price)
{
    bool found = false;
    for (int i=0; i<arr_len; ++i)
    {
        if (arr[i].price == price)
        {
            printf("%s - %s\n", arr[i].owner_name, arr[i].chip_code);
            found = true;
        }
    }
    if (!found)
        printf("No data found!\n");
}

float binary_function(float price)
{
    FILE *fptr_b = fopen("PatientsBin.bin", "rb");
    if (fptr_b == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    Patient buff;

    while (true)
    {
        if (fread(&buff, sizeof(buff), 1, fptr_b)!=1)
        {
            printf("Reading error!");
            fclose(fptr_b);
            break;
        }
        if (buff.price >= price)
        {
            printf("Bin Owner Name: %s\n", buff.owner_name);
            printf("Bin Code: %s\n", buff.chip_code);
            printf("Bin Price: %.2f\n", buff.price);
            puts("----------\n");
        }
        else
            printf("No data found!\n");
    }
}

int main()
{
    int total_patients;
    printf("Enter total patients number: ");
    scanf("%d", &total_patients);

    Patient *patients_arr = (Patient*)malloc(total_patients * sizeof(Patient));

    FILE *fptr = fopen("PatientsText.txt", "w");
    if (fptr == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    fclose(fptr);

    for (int i=0; i<total_patients; ++i)
    {
        patients_arr[i] = create_new_patient();
    }
    float input_price;
    printf("Enter price to search: ");
    scanf("%f", &input_price);
    search_function(patients_arr, total_patients, input_price);
    binary_function(input_price);

    free(patients_arr);

    return 0;
}
