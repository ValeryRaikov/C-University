#include <stdio.h>

int term[1000];

int fib(int k) {
    if (k <= 1)
    return k;

    if (term[k] != 0)
        return term[k];

    term[k] = fib(k-1) + fib(k-2);
    return term[k];    
}

int main() {
    int pos;
    printf("Entre fibonacci series position: ");
    scanf("%d", &pos);

    printf("Number at position %d is: %d", pos, fib(pos));

    return 0;
}