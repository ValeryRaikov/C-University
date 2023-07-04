#include <stdio.h>

int find_len(int arr[])
{
    int count=0;
    for(int i=0; arr[i]!='\0'; ++i)
    {
        count++;
    }
    return count;
}

int find_max(int arr[], int size)
{
    int max=arr[0];
    for(int i=0; i<size; ++i)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int find_min(int arr[], int size)
{
    int min=arr[0];
    for(int i=0; i<size; ++i)
    {
        if(arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

int find_average(int arr[], int size)
{
    int sum, average;
    for(int i=0; i<size; ++i)
    {
        sum+=arr[i];
    }
    average = sum/size;
}

void swap_pos(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int arr[], int size)
{
    for(int i=0; i<size-1; ++i)
    {
        for(int j=0; j<size-i-1; ++j)
        {
            if(arr[j] > arr[j+1])
                swap_pos(&arr[j], &arr[j+1]);
        }
    }
}

void print_sorted_arr(int arr[], int size)
{
    printf("Sorted array is:\n");
    for(int i=0; i<size; ++i)
        printf("%d ", arr[i]);
    putchar('\n');
}

int filter_arr(int arr[], int size)
{
    int *ptr = &arr;
    int count1, count2;
    for(int i=0; i<size; ++i)
    {
        if(*(ptr+i)%2==0)
            count1++;
        else
            count2++;
    }
    int filter[2];
    filter[0]=count1;
    filter[1]=count2;

    return filter;
}

int main()
{
    int numbers[] = {1,4,9,6,7,3,'\0'};
    int numbers2[] = {1,4,9,6,7,3};
    int size = sizeof(numbers2)/sizeof(numbers2[0]);
    printf("Length of array is: %d\n", find_len(numbers));
    printf("Biggest number is: %d\n", find_max(numbers2, size));
    printf("Smallest number is: %d\n", find_min(numbers2, size));
    printf("Average number is: %d\n", find_average(numbers2, size));

    int num1, num2;
    printf("Enter numbers:\n");
    scanf("%d %d", &num1, &num2);
    printf("Before swap-> num1=%d, num2=%d\n", num1, num2);
    swap_pos(&num1, &num2);
    printf("After swap-> num1=%d, num2=%d\n", num1, num2);

    bubble_sort(numbers, size);
    print_sorted_arr(numbers, size);

    printf("Total even/odd nums: %d\n", filter_arr(numbers2, size));

    return 0;
}
