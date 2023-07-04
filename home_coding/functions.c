#include <stdio.h>

int check_max_number(int arr[], int arr_length)
{
    int max = 0;
    for (int i=0; i<arr_length; ++i)
    {
        if (arr[i] > max)
                max = arr[i];
    }
    return max;
}

int main()
{
    int length;
    printf("Enter size of the array: ");
    scanf("%d", &length);

    int numbers[length];
    printf("Create your array: ");
    for (int i=0; i<length; ++i)
    {
        printf("Enter arr[%d]: ", i);
        scanf("%d", &numbers[i]);
    }

    int result = check_max_number(numbers, length);
    printf("The max value of the array is: %d", result);

    return 0;
}
