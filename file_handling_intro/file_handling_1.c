#include <stdio.h>

int main()
{
    FILE *bin_fp, *txt_fp;
    int count_even = 0, count_odd = 0;
    int n, num;

    bin_fp = fopen("numbers.bin", "rb");

    if (bin_fp == NULL)
    {
        printf("Error opening file!");
        return 1;
    }

    fread(&n, sizeof(int), 1, bin_fp);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        fread(&num, sizeof(int), 1, bin_fp);

        arr[i] = num;
        while (num != 0)
        {
            int digit = num % 10;

            if (digit % 2 == 0)
                count_even++;
            else
                count_odd++;

            num /= 10;
        }
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

    printf("Total count of even digits: %d\n", count_even);
    printf("Total count of odd digits: %d\n", count_odd);

    return 0;
}
