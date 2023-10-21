#include <stdio.h>

int main() {
    int n;

    printf("Enter number of rows and cols: ");
    scanf("%d", &n);

    int matrix[n][n];

    printf("Enter matrix values:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += matrix[i][n - 1 - i];
    }

    printf("Sum of elements of secondary diagonal: %d\n", sum);

    return 0;
}

