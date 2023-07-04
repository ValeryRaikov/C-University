#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    printf("Enter the size of the array: ");
    do
    {
        scanf("%d", &size);
    }
    while (size <= 0);

    int *data = (int*)malloc(size * sizeof(int));
    if (data == NULL)
    {
        perror("Dynamic memory error!");
        exit(1);
    }

    printf("Enter numbers:\n");
    for (int i=0; i<size; ++i)
    {
        scanf("%d", &data[i]);
    }

    FILE *fptr;
    fptr = fopen("binary_file.bin", "wb");
    if (fptr == NULL)
    {
        perror("Error opening the file!");
        exit(1);
    }

    if (fwrite(data, 1, sizeof(data), fptr)<1)
    {
        perror("Error writing in file!");
        exit(1);
    }

    int *buffer = (int*)malloc(size * sizeof(int));

    fptr = fopen("binary_file.bin", "rb");
    if (fptr == NULL)
    {
        perror("Error opening the file!");
        exit(1);
    }

    if (fread(buffer, sizeof(int), 1, fptr)!=1)
    {
        perror("Error reading from file!");
        exit(1);
    }

    printf("Info read from file:\n");
    for (int i = 0; i < size; ++i)
    {
       printf("data[%d] = %d\n", i, buffer[i]);
    }

    fclose(fptr);

    free(data);
    free(buffer);

    return 0;
}
