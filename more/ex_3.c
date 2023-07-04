#include <stdio.h>

int main()
{
    int size, arr[size], i;
    printf("Enter the size:\n");
    scanf("%d", &size);
    printf("Enter the elements:\n");
    for(i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }
    int rev[size], j = 0;
    for(i=size-1; i>=0; i--)
    {
        rev[j] = arr[i];
        j++;
    }
    printf("The reversed array is:\n");
    for(i=0; i<size; i++)
    {
        printf("%d", rev[j]);
    }

    return 0;
}
