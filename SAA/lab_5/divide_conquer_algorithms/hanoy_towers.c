#include <stdio.h>

const unsigned N = 3;

void diskMove(unsigned N, char a, char b)
{
    printf("%u%c%c\n", N, a, b);
}

void hanoy(char a, char c, char b, unsigned numb)
{
    if (1 == numb)
        diskMove(1, a, c);
    else
    {
        hanoy(a, b, c, numb-1);
        diskMove(numb, a, c);
        hanoy(b, c, a, numb-1);
    }
}

int main()
{
    printf("%u\n", N);
    hanoy('A', 'C', 'B', N);
    return 0;
}
