#include <stdio.h>

int main() {
    int rows;

    printf("Enter number of rows/cols: ");
    scanf("%d", &rows);

    int matrix[rows][rows];

    printf("Create the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            printf("Enter number at position [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    int symmetricPairsCount = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = i + 1; j < rows; j++) {
            if (matrix[j][i] > matrix[i][j]) {
                symmetricPairsCount++;
            }
        }
    }

    /*
    Same algorithm to find pairs where the element below is smaller
    int symmetricPairsCount = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = i + 1; j < rows; j++) {
            if (matrix[j][i] > matrix[i][j]) {
                symmetricPairsCount++;
            }
        }
    }
    */

    printf("Number of pairs of elements symmetric with respect to the main diagonal where the element above is smaller: %d\n", symmetricPairsCount);

    return 0;
}

