#include <stdio.h>

void quicksort(int lo, int hi, int arr[]) {
    int i = lo, j = hi, h;
    int x = arr[(lo + hi) / 2];
    do {
        while (arr[i] < x)
            i++;
        while (arr[j] > x)
            j--;
        if (i <= j) {
            h = arr[i];
            arr[i] = arr[j];
            arr[j] = h;
            i++;
            j--;
        }
    } while (i <= j);
    if (lo < j)
        quicksort(lo, j, arr);
    if (i < hi)
        quicksort(i, hi, arr);
}

int main() {
    int size;
    printf("Enter size of the array: ");
    scanf("%d", &size);
    int arr[size];

    int i;
    printf("Enter the elements of one-dimensional array\n");
    for (i = 0; i < size; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    quicksort(0, size - 1, arr);

    printf("\nThe sorted elements of one-dimensional array\n");
    for (i = 0; i < size; i++)
        printf("arr[%d] = %d\n", i, arr[i]);

    return 0;
}
