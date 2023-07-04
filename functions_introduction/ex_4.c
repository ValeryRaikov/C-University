#include <stdio.h>

long int dec_to_bin(long int n);

void main()
{
    int number;
    printf("Enter number:\n");
    scanf("%d", &number);
    long int res = dec_to_bin(number);
    printf("%ld", res);
}
long int dec_to_bin(long int n)
{
    long int binary=0, rem, num, base=1;
    num = n;
    while (num!=0)
    {
        rem = num%2;
        binary = binary+base * rem;
        base *= 10;
        num /= 2;
    }
    return binary;
}
