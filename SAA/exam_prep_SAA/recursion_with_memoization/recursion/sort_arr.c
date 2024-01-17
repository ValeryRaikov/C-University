#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (1) {
        while (i <= j && arr[i] <= pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i <= j) {
            swap(&arr[i], &arr[j]);
        } else {
            break;
        }
    }

    swap(&arr[low], &arr[j]);
    return j;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int n;
    printf("Enter number of elements to sort: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter element at pos[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    quicksort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
