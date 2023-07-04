#include <stdio.h>
#include <stdlib.h>


int cmp_func (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}


void reverse (int arr[], int n)
{
    for(int i = 0; i < n/2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
}


int kth_largest_element(int arr[], int k, int n)
{
    qsort(arr, n, sizeof(int), cmp_func);

    reverse(arr, n);

    return arr[k-1];
}

int main()
{

    int arr[] = {12, 15, 7, 3, 8, 16, 25};

    int n = sizeof(arr) / sizeof(arr[0]);

    int k;
    printf("Enter k:\n");
    scanf("%d", &k);

    printf("The %dth largest element = %d", k, kth_largest_element(arr, k, n));
    return 0;
}

