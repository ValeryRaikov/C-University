#include <stdio.h>

int arr_length(int arr[])
{
    int i, count;
    for(i=0; arr[i]!='\0'; i++)
    {
        count++;
    }
    return count;
}

int main()
{
    int numbers[] = {1,2,3,4,5,6, '\0'};
    int size = arr_length(numbers);
    printf("Length of array is: %d\n", size);

    int length;
    printf("Choose array length:\n");
    scanf("%d", &length);
    int numbers2[length];
    printf("Create your array:\n");
    int num;
    for(int i=0; i<length; ++i)
    {
        scanf("%d", &num);
        numbers2[i] = num;
    }

    return 0;
}
