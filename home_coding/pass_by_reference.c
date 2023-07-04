#include <stdio.h>

void swap_numbers(int *a, int *b);
int calculate_sum(int *a, int *b);
int calculate_sum_of_arr(int arr[], int size);

int main()
{
    int x = 15;
    int y = 20;
    printf("Numbers before swap-> x:%d - y:%d\n", x, y);

    swap_numbers(&x, &y);
    printf("Numbers after swap-> x:%d - y:%d\n", x, y);

    int result1 = calculate_sum(&x, &y);
    printf("Sum is %d\n", result1);

    int numbers[] = {7, 5, 9, 1, 3, 4, '\0'};
    int size = sizeof(numbers)/sizeof(numbers[0]);

    int result2 = calculate_sum_of_arr(numbers, size);
    printf("Sum of array is %d", result2);

    return 0;
}

void swap_numbers(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int calculate_sum(int *a, int *b)
{
    return *a + *b;
}

int calculate_sum_of_arr(int arr[], int size)
{
    int sum = 0;
    for (int i=0; i<size; ++i)
    {
        sum += arr[i];
    }

    return sum;
}
