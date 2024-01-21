#include <stdio.h>
#include <math.h>

const unsigned n = 53;

char isPrime(unsigned n) {
    unsigned i = 2;

    if (n == 2)
        return 1;

    while (i <= sqrt(n)) 
    {
        if (n % i == 0)
            return 0;

        i++;
    }

    return 1; 
}

int main() {
    if (isPrime(n))
        printf("Number %u is prime.\n", n);
    else
        printf("Number %u is not prime.\n", n);
    return 0;
}