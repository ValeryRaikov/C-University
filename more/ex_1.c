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

void check(int array[], int n)
{
    int count = 1;
    int max = 0;
    int el = 0;
    int final_max = 0;
    for(int i = 0; i<n; ++i)
    {
        for(int j=i+1; j<=n; ++j)
        {
           if(array[i] == array[j])
            {
                count ++;
            }
            else
            {
                max = count;
                count = 1;
            }
            if (max > final_max)
            {
                el = array[i];
                 final_max = max;
            }

        }
    }
        printf("Most total numbers(%d) -> %d",el, final_max);
}

void print_array(int array[], int size)
{
    for(int i=0; i<size; ++i)
        printf("%d\n", array[i]);
}

int main()
{
    int numbers[10] = {1, 5, 2, 7, 2, 2, 8, 3, 6, 6};
    int n = sizeof(numbers)/sizeof(numbers[0]);
    bubble_sort(numbers, n);
    printf("Sorted array:\n");
    print_array(numbers, n);

    //Sorted array is given here after bubble sort function:
    int sorted_array[] = {1,2,2,2,3,5,6,6,7,8};
    check(sorted_array, n);

    return 0;
}
