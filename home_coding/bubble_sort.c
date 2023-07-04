#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int array[], int n)
{
    int i, j;
    for(i=0; i<n-1; ++i)
    {
        for(j=0; j<n-i-1; ++j)
        {
            if(array[j]>array[j+1])
                swap(&array[j], &array[j+1]);
        }
    }
}

void print_array(int array[], int size)
{
    for(int i=0; i<size; ++i)
        printf("%d\n", array[i]);
}

void main()
{
    int numbers[10] = {1, 5, 9, 7, 3, 4, 8, 2, 10, 6};
    int n = sizeof(numbers)/sizeof(numbers[0]);
    bubble_sort(numbers, n);
    printf("Sorted array:\n");
    print_array(numbers, n);
}
