#include <stdio.h>

#define MAX_LENGTH 10

void create_arr(int *arr) {
    for (int i=0; i<MAX_LENGTH; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
}

void mergeArrays(int A[], int B[], int C[], int D[]) {
    int hashTable[MAX_LENGTH * 3] = {0}; 
    int idxD = 0;

    for (int i = 0; i < MAX_LENGTH; i++) {
        hashTable[A[i]]++;
        hashTable[B[i]]++;
        hashTable[C[i]]++;
    }

    for (int i = 1; i <= MAX_LENGTH; i++) {
        if (hashTable[i] >= 3) {
            D[idxD++] = i;
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

    mergeArrays(A, B, C, D);

    printf("Merged array D containing common elements: ");
    for (int i = 0; i < MAX_LENGTH && D[i] != 0; i++) {
        printf("%d ", D[i]);
    }

    return 0;
}
