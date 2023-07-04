#include <stdio.h>

int main()
{
    int size, array[size], i;
    printf("Enter array size:\n");
    scanf("%d", &size);
    printf("Fill the array:\n");
    for(i=0; i<size; ++i)
    {
        scanf("%d", &array[i]);
    }
    int reversed[size], j = 0;
    for(i=size-1; i>=0; --i)
    {
        reversed[j] = array[i];
        j++;
    }
    printf("The reversed array is:\n");
    for(i=0; i<size; ++i)
    {
        printf("%d ", reversed[i]);
    }

    return 0;
}

