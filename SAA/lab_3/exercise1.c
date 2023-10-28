#include <stdio.h>

int main() {
    int size;
    printf("Enter the size of the matrix: ");
    scanf("%d", &size);

    int two_dimensional_array[size][size];

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("Enter matrix element [%d][%d]: ", i, j);
            scanf("%d", &two_dimensional_array[i][j]);
        }
    }

    int secondary_diagonal_sum = 0;
    int i, j;
    int one_dimensional_array[size];

    for (i = 0; i < size; ++i) {
        secondary_diagonal_sum += two_dimensional_array[i][size - 1 - i];
    }

    if (secondary_diagonal_sum % 2 != 0) {
        for (i = 0; i < size; ++i) {
            one_dimensional_array[i] = two_dimensional_array[i][i];
        }
        printf("The sum of elements along the secondary diagonal is odd.\n");
        printf("The one-dimensional array with elements from the main diagonal is: ");
        for (i = 0; i < 3; i++) {
            printf("%d ", one_dimensional_array[i]);
        }
    } else {
        printf("The sum of elements along the secondary diagonal is even.\n");
    }

    return 0;
}

