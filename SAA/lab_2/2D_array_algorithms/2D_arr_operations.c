#include <stdio.h>

int main() {
    int rows, cols;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of cols: ");
    scanf("%d", &cols);

    if (rows != cols) {
        printf("The matrix should be square (with the same number of rows and columns).\n");
        return 1;
    }

    int matrix[rows][cols];

    printf("Enter matrix values:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i < j) {
                if (matrix[i][j] % 2 == 1) {
                    matrix[i][j]++;
                }
            } else if (i > j) {
                if (matrix[i][j] % 2 == 0) {
                    matrix[i][j]--;
                }
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        matrix[i][i]++;
    }

    printf("Modified matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

