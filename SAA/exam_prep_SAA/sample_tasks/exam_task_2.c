#include <stdio.h>

// Функция за проверка дали число е част от редицата на Фибоначи
int is_fibonacci(int num) {
    int a = 0, b = 1, c;
    while (a <= num) {
        if (a == num) {
            return 1; // Числото е част от редицата на Фибоначи
        }
        c = a + b;
        a = b;
        b = c;
    }
    return 0; // Числото не е част от редицата на Фибоначи
}

int main() {
    int n;

    printf("Enter the size of the matrix: ");
    scanf("%d", &n);

    int matrix[n][n];

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("matrix[%d][%d] = ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Elements on the secondary diagonal: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", matrix[i][n - i - 1]);
    }
    printf("\n");

    int isFibonacciSequence = 1;
    for (int i = 0; i < n; i++) {
        if (!is_fibonacci(matrix[i][n - i - 1])) {
            isFibonacciSequence = 0;
            break;
        }
    }

    if (isFibonacciSequence) {
        printf("The elements on the secondary diagonal form a Fibonacci sequence.\n");
    } else {
        printf("The elements on the secondary diagonal do not form a Fibonacci sequence.\n");
    }

    return 0;
}
