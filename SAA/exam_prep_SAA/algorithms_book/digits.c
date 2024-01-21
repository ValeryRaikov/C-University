#include <stdio.h>

int main() {
    unsigned n;
    printf("Enter a random positive number: ");
    scanf("%u", &n);

    unsigned digits;
    for (digits=0; n>0; n/=10, digits++);

    printf("Your number contains %u digits.", digits);

    return 0;
}