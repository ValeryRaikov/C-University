#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *bin_fp, *txt_fp;
    int n, num, even_sum = 0, odd_sum = 0;

    bin_fp = fopen("numbers.bin", "rb");

    if (bin_fp == NULL)
    {
        printf("Error opening binary file!");
        return 1;
    }

    fread(&n, sizeof(int), 1, bin_fp);

    int *arr = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        fread(&num, sizeof(int), 1, bin_fp);

        int even_digits = 0, odd_digits = 0;

        while (num != 0)
        {
            int digit = num % 10;

            if (digit % 2 == 0)
                even_digits++;
            else
                odd_digits++;

            num /= 10;
        }

        even_sum += even_digits;
        odd_sum += odd_digits;

        arr[i] = num;
    }

    fclose(bin_fp);

    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    txt_fp = fopen("sorted_numbers.txt", "w");

    if (txt_fp == NULL)
    {
        printf("Error opening text file!");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        fprintf(txt_fp, "%d\n", arr[i]);
    }

    fclose(txt_fp);
    free(arr);

    printf("Total sum of even digits: %d\n", even_sum);
    printf("Total sum of odd digits: %d\n", odd_sum);

    return 0;
}
