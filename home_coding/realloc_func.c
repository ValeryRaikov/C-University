#include <stdio.h>
#include <stdlib.h>

#define CONST_NUM 10

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *numbers = (int*)malloc(size * sizeof(int));

    printf("Enter numbers:\n");
    for (int i=0; i<size; ++i)
    {
        scanf("%d", &numbers[i]);
    }

    for (int i=0; i<size; ++i)
    {
        printf("arr[%d] = %d\n", i+1, numbers[i]);
    }

    int add;
    printf("Enter additional numbers to be added:\n");
    scanf("%d", &add);
    numbers = realloc(numbers, (size+add) * sizeof(int));

    for (int i=size; i<(size+add); ++i)
    {
        printf("arr[%d] = %d\n", i+1, CONST_NUM);
    }

    free(numbers);

    return 0;
}
