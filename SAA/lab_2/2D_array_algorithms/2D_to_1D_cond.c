#include <stdio.h>

int main() {
    int rows, cols;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of cols: ");
    scanf("%d", &cols);

    int matrix[rows][cols];

    printf("Enter matrix values:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    int result[rows + 1];

    int diagonal_sum = 0;
    for (int i = 0; i < rows; i++) {
        diagonal_sum += matrix[i][i];
    }
    result[0] = diagonal_sum;

    for (int i = 0; i < rows; i++) {
        int row_sum = 0;
        for (int j = 0; j < cols; j++) {
            row_sum += matrix[i][j];
        }
        result[i + 1] = row_sum;
    }

    int below_diagonal_count = 0;
    for (int i = 1; i < rows; i++) {
        for (int j = 0; j < i; j++) {
            if (matrix[i][j] < i + j) {
                below_diagonal_count++;
            }
        }
    }
    result[rows] = below_diagonal_count;

    printf("Resultant array is:\n");
    for (int i = 0; i <= rows; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}

