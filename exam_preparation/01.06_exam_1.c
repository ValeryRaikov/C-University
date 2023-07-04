#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    int id;
    char artist_name[32];
    char picture_name[32];
    float price;
} Picture;

float calculate_avg(Picture *arr, int arr_len, float price);
int work_with_txt(Picture *arr, int arr_len, char symbol);
void work_with_bin(char artist_name[]);

int main()
{
    int n;
    do
    {
        printf("Enter number of pictures: ");
        scanf("%d", &n);
    } while (n < 3 || n > 30);

    Picture *pic_arr = (Picture*)calloc(n, sizeof(Picture));
    if (pic_arr == NULL)
    {
        printf("Dynamic memory error!");
        exit(1);
    }

    for (int i=0; i<n; ++i)
    {
        printf("Enter picture id: ");
        scanf("%d", &pic_arr[i].id);
        printf("Enter artist name: ");
        fflush(stdin);
        if (fgets(pic_arr[i].artist_name, sizeof(pic_arr[i].artist_name), stdin)==NULL)
        {
            printf("Input error!");
            exit(1);
        }
        pic_arr[i].artist_name[strlen(pic_arr[i].artist_name)-1] = '\0';
        fflush(stdin);
        printf("Enter picture name: ");
        if (fgets(pic_arr[i].picture_name, sizeof(pic_arr[i].picture_name), stdin)==NULL)
        {
            printf("Input error!");
            exit(1);
        }
        pic_arr[i].picture_name[strlen(pic_arr[i].picture_name)-1] = '\0';
        fflush(stdin);
        printf("Enter price: ");
        scanf("%f", &pic_arr[i].price);
    }
    float test_func1 = calculate_avg(pic_arr, n, 250.00);
    printf("Average result: %.2f\n", test_func1);

    int test_func2 = work_with_txt(pic_arr, n, 'V');
    printf("Total matches: %d\n", test_func2);

    work_with_bin("Vasil");

    free(pic_arr);

    return 0;
}

float calculate_avg(Picture *arr, int arr_len, float price)
{
    bool isFound = false;
    float prices = 0;
    int counter = 0;
    for (int i=0; i<arr_len; ++i)
    {
        if (arr[i].price >= price)
        {
            isFound = true;
            prices += arr[i].price;
            counter++;
        }
    }

    if (isFound)
    {
        float avg_res = prices / counter;
        return avg_res;
    }
    else
        return 0;
}

int work_with_txt(Picture *arr, int arr_len, char symbol)
{
    FILE *fptr = fopen("info.txt", "w");
    if (fptr == NULL)
    {
        printf("Error opening file!");
        exit(1);
    }

    bool isFound = false;
    int counter = 0;
    for (int i=0; i<arr_len; ++i)
    {
        if (arr[i].artist_name[0] == symbol)
        {
            isFound = true;
            counter++;
            if (fprintf(fptr, "%d;%s;%.2fleva\n", arr[i].id, arr[i].picture_name, arr[i].price)<0)
            {
                printf("Writing error!");
                exit(1);
            }
        }
    }
    fclose(fptr);

    if (isFound)
        return counter;
    else
        return 0;
}

void work_with_bin(char artist_name[])
{
    FILE *fptr = fopen("picture.bin", "rb");
    if (fptr == NULL)
    {
        printf("Error opening file!");
        exit(1);
    }

    Picture buff;
    bool isFound = false;
    while (fread(&buff, sizeof(Picture), 1, fptr)==1)
    {
        if (strcmp(buff.artist_name, artist_name)==0)
        {
            isFound = true;
            printf("Picture title: %s\n", buff.picture_name);
            printf("Price: %.2f\n", buff.price);
            puts("====================\n");
        }
    }
    if (!isFound)
        printf("No data!\n");

    fclose(fptr);
}
