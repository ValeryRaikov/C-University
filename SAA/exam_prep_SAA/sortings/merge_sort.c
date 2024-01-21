#include <stdio.h>

#define MAX_SIZE 100

int arr[MAX_SIZE];
int temp[MAX_SIZE];

void merge(int left, int mid, int right) {
    int i, left_end, num_elements, tmp_pos;
    left_end = mid - 1;
    tmp_pos = left;
    num_elements = right - left + 1;
    while ((left <= left_end) && (mid <= right)) {
        if (arr[left] <= arr[mid]) {
            temp[tmp_pos] = arr[left];
            tmp_pos = tmp_pos + 1;
            left = left + 1;
        } else {
            temp[tmp_pos] = arr[mid];
            tmp_pos = tmp_pos + 1;
            mid = mid + 1;
        }
    }
    while (left <= left_end) {
        temp[tmp_pos] = arr[left];
        left = left + 1;
        tmp_pos = tmp_pos + 1;
    }
    while (mid <= right) {
        temp[tmp_pos] = arr[mid];
        mid = mid + 1;
        tmp_pos = tmp_pos + 1;
    }
    for (i = 0; i < num_elements; i++) {
        arr[right] = temp[right];
        right = right - 1;
    }
}

void m_sort(int left, int right) {
    int mid;
    if (right > left) {
        mid = (right + left) / 2;
        m_sort(left, mid);
        m_sort(mid + 1, right);
        merge(left, mid + 1, right);
    }
}

void mergeSort(int array_size) {
    m_sort(0, array_size - 1);
}

int main() {
    int size;
    printf("Enter size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of one-dimensional array:\n");
    for (int i = 0; i < size; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    mergeSort(size);

    printf("\nThe sorted elements of one-dimensional array:\n");
    for (int j = 0; j < size; j++)
        printf("a[%d] = %d\n", j, arr[j]);

    return 0;
}