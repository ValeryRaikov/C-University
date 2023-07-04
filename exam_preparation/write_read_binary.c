#include <stdio.h>

int main()
{
    int data[] = {0,1,2,3,4,5,6,7,8,9};

    FILE *fp = fopen("bin_file.bin", "wb");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    if (fwrite(data, sizeof(data), 1, fp)!=1)
    {
        printf("Error writing in file!");
        exit(1);
    }

    fclose(fp);

    fp = fopen("bin_file.bin", "rb");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }
    int buff[11];

    if (fread(buff, sizeof(buff), 1, fp)!=0)
    {
        printf("Error reading from file!");
        exit(1);
    }

    for (int i=0; i<10; ++i)
    {
        printf("Buff[%d] = %d\n", i, buff[i]);
    }

    return 0;
}
