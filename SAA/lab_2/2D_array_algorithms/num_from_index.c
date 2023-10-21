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

    int row, col;

    printf("Enter row index: ");
    scanf("%d", &row);
    printf("Enter col index: ");
    scanf("%d", &col);

    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        int element = matrix[row][col];
        printf("Element at matrix[%d][%d] is: %d\n", row, col, element);
    } else
        printf("Invalid indices. Please enter valid row and column indices.\n");

    return 0;
}

