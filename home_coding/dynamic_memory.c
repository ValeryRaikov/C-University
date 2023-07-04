#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *arr_numbers;
    arr_numbers = (int*)malloc(size * sizeof(int));

    if (arr_numbers == NULL)
    {
        perror("Dynamic memory error!");
        exit(1);
    }

    printf("Fill array:\n");
    for (int i=0; i<size; ++i)
    {
        printf("Number[%d]: ", i);
        scanf("%d", arr_numbers+i);
    }

    printf("Output array values:\n");
    for (int i=0; i<size; ++i)
        printf("%d\n", *(arr_numbers+i));

    printf("Output array addresses:\n");
    for (int i=0; i<size; ++i)
        printf("%p\n", arr_numbers+i);

    //Dynamically allocate more memory for additional elements to be added!:
    int new_size;
    printf("Enter the new size: ");
    scanf("%d", &new_size);

    arr_numbers = realloc(arr_numbers, new_size * sizeof(int));

    printf("Output array addresses of the new dynamic array:\n");
    for (int i=0; i<new_size; ++i)
    {
        printf("%p\n", arr_numbers+i);
    }

    free(arr_numbers);

    int *arr_numbers_2;
    arr_numbers_2 = (int*)calloc(new_size, sizeof(int));
    printf("Output calloc values of the dynamic array:");
    for (int i=0; i<new_size; ++i)
    {
        printf("%d\n", *(arr_numbers_2+i));
    }

    return 0;
}
