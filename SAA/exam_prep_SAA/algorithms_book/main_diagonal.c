#include <stdio.h>

#define MAX 5
int arr[MAX][MAX];

int main() {
    printf("Create matrix:\n");
    for (int i=0; i<MAX; i++) {
        for (int j=0; j<MAX; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    } 

    printf("Your matrix with 0 on the main diagonal:\n");
    for (int i=0; i<MAX; i++) {
        for (int j=0; j<MAX; j++) {
            if (i == j)
                arr[i][j] = 0;

            printf("%d ", arr[i][j]);
        }
        printf("\n");
    } 

    return 0;
}