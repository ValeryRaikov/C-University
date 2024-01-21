#include <stdio.h>

int sub_nums(int n) {
    if (n <= 1) 
        return n;

    return n - sub_nums(n-1);
}

int main() {
    int num;
    printf("Enter a whole number: ");
    scanf("%d", &num);

    int result = sub_nums(num);
    printf("Subtraction of all numbers up to %d is %d", num, result);

    return 0;
}
