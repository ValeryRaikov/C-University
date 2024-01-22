#include <stdio.h>

#define MAX 1000
int fib_arr[MAX];

long long fib(int n) {
    if (n <= 1)
        return n;

    if (fib_arr[n] == -1)
        fib_arr[n] = fib(n-1) + fib(n-2);

    return fib_arr[n];
     
}

int main() {
    // Initialize first 2 values so taht the algorithm works
    fib_arr[0] = 0;
    fib_arr[1] = 1;

    for (int i=0; i<MAX; i++) 
        fib_arr[i] = -1;

    int num;
    printf("Enter a whole number: ");
    scanf("%d", &num);

    printf("Fibonacci value at position %d is %lld", num, fib(num));

    return 0;
}