#include <stdio.h>

#define MAX 100

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int *arr) {
    for (int i=0; i <MAX-1; i++) {
        for (int j=0; j < MAX-i-1; j++) {
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
}

int main() {
    int arr[MAX];
    printf("Fill the array with 100 elements!\n");
    for (int i=0; i < MAX; i++) {
        printf("Arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    bubble_sort(arr);

    int result = arr[5];

    printf("The greatest number from smallest to greatest is: %d", result);

    return 0;
}