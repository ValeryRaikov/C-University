#include <stdio.h>

void siftDown(int root, int bottom, int arr[]) {
    int done, maxChild, temp;
    done = 0;
    while ((root * 2 <= bottom) && (!done)) {
        if (root * 2 == bottom)
            maxChild = root * 2;
        else if (arr[root * 2] > arr[root * 2 + 1])
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;
        if (arr[root] < arr[maxChild]) {
            temp = arr[root];
            arr[root] = arr[maxChild];
            arr[maxChild] = temp;
            root = maxChild;
        } else
            done = 1;
    }
}

void heapSort(int array_size, int arr[]) {
    int i, temp;
    for (i = (array_size / 2) - 1; i >= 0; i--)
        siftDown(i, array_size, arr);
    for (i = array_size - 1; i >= 1; i--) {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        siftDown(0, i - 1, arr);
    }
}

int main() {
    int size;
    printf("Enter size of the array: ");
    scanf("%d", &size);
    int arr[size];

    int j;
    printf("Enter the elements of one-dimensional array\n");
    for (j = 0; j < size; j++) {
        printf("arr[%d] = ", j);
        scanf("%d", &arr[j]);
    }
    heapSort(size, arr);
    printf("\nThe sorted elements of one-dimensional array\n");
    for (j = 0; j < size; j++)
        printf("arr[%d] = %d\n", j, arr[j]);
    return 0;
}
