#include <stdio.h>

#define MAX_LENGTH 10

void create_arr(int *arr) {
    for (int i=0; i<MAX_LENGTH; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
}

void swap_pos(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_arr(int arr[]) {
    for (int i = 0; i < MAX_LENGTH - 1; i++) {
        for (int j = 0; j < MAX_LENGTH - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap_pos(&arr[j], &arr[j+1]);
            }
        }
    }
}

void merge_arr(int A[], int B[], int C[], int D[]) {
    int i = 0, j = 0, k = 0, idxD = 0;

    while (i < MAX_LENGTH && j < MAX_LENGTH && k < MAX_LENGTH) {
        if (A[i] == B[j] && B[j] == C[k]) {
            D[idxD++] = A[i];
            i++;
            j++;
            k++;
        } else if (A[i] < B[j] || A[i] < C[k]) {
            i++;
        } else if (B[j] < A[i] || B[j] < C[k]) {
            j++;
        } else {
            k++;
        }
    }
}

int main() {
    int A[MAX_LENGTH], B[MAX_LENGTH], C[MAX_LENGTH], D[MAX_LENGTH];

    printf("Create array A:\n");
    create_arr(A);

    printf("Create array B:\n");
    create_arr(B);

    printf("Create array C:\n");
    create_arr(C);

    sort_arr(A);
    sort_arr(B);
    sort_arr(C);

    merge_arr(A, B, C, D);

    printf("Merged array D containing common elements: ");
    for (int i = 0; i < MAX_LENGTH && D[i] != 0; i++) {
        printf("%d ", D[i]);
    }

    return 0;
}
