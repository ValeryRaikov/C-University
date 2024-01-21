#include <stdio.h>

#define MAX 10

int arr[MAX];

int *sort_arr(int arr[MAX]) {
    int sorted_arr[MAX];
    int used[MAX] = {0}; 

    int flag = MAX;

    do {
        int min_el = -1;
        int min_index = -1;

        for (int j = 0; j < MAX; j++) {
            if (!used[j] && (min_el == -1 || arr[j] < min_el)) {
                min_el = arr[j];
                min_index = j;
            }
        }

        if (min_index != -1) {
            sorted_arr[MAX - flag] = min_el;
            used[min_index] = 1; 
            flag--;
        }

    } while (flag > 0);

    for (int k = 0; k < MAX; k++) {
        arr[k] = sorted_arr[k];
    }

    return arr;

}

int main() {
    printf("Create your array:\n");
    for (int i = 0; i < MAX; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    sort_arr(arr);

    printf("Sorted array:\n");
    for (int i = 0; i < MAX; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
