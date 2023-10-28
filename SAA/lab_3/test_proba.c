#include <stdio.h>

int main() {
    int size;
    printf("Enter the size of the square matrix: ");
    scanf("%d", &size);

    int two_dimensional_array[size][size];
    int i, j;

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("Enter element at pos [%d][%d]", i, j);
            scanf("%d", &two_dimensional_array[i][j]);
        }
    }

    printf("Matrix:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%2d ", two_dimensional_array[i][j]);
        }
        printf("\n");
    }

    int total_sum = 0;
    for (i = 0; i < size; i++) {
        int secondary_diagonal_sum = 0;
        for (j = 0; j < size; j++) {
            if (j != i) {
                secondary_diagonal_sum += two_dimensional_array[i][j];
            }
        }
        total_sum += secondary_diagonal_sum;
        printf("Element at [%d][%d]: %d\n", i, i, secondary_diagonal_sum);
    }

    printf("Sum of each element in the secondary diagonal with other elements: %d\n", total_sum);

    return 0;
}

