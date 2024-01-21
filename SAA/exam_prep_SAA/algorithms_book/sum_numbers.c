#include <stdio.h>

int sum_nums(int n) {
    if (n <= 1) 
        return n;

    return n + sum_nums(n-1);
}

int main() {
    int num;
    printf("Enter a whole number: ");
    scanf("%d", &num);

    int result = sum_nums(num);
    printf("Sum of all numbers up to %d is %d", num, result);

    return 0;
}