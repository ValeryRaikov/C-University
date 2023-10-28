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

    int diagonal_pair_sums[size - 1];
    int one_dimensional_array[size];

    for (int i = 0; i < size; ++i) {
        diagonal_pair_sums[i] = two_dimensional_array[i][size - i - 1] + two_dimensional_array[i + 1][size - i - 2];
    }

    int secondary_diagonal_sum = 0;

    for (int i = 0; i < size - 1; ++i) {
        secondary_diagonal_sum += diagonal_pair_sums[i];
    }

    if (secondary_diagonal_sum % 2 != 0) {
        for (int i = 0; i < size; ++i) {
            one_dimensional_array[i] = two_dimensional_array[i][i];
        }
        printf("The sum of elements along the secondary diagonal is odd -> %d\n", secondary_diagonal_sum);
        printf("The one-dimensional array with elements from the main diagonal is: ");
        for (int i = 0; i < size; ++i) {
            printf("%d ", one_dimensional_array[i]);
        }
    } else {
        printf("The sum of elements along the secondary diagonal is even -> %d\n", secondary_diagonal_sum);
    }

    return 0;
}

