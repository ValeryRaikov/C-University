#include <stdio.h>
#include <stdbool.h>

int main()
{
    FILE *bin_fp;

    bin_fp = fopen("numbers.bin", "wb");

    if (bin_fp == NULL)
    {
        printf("Error opening file!");
        return 1;
    }

    int x;
    while (true)
    {
        printf("Enter an integer (0 to stop): ");
        scanf("%d", &x);
        if (x == 0)
        {
            break;
        }
        fwrite(&x, sizeof(x), 1, bin_fp);
    }

    fclose(bin_fp);

    printf("File written successfully.\n");

    return 0;
}
