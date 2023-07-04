#include <stdio.h>
int main()
{
    int letter = 'a';
    while (letter <= 'z')
    {
        printf("%c : %d\n", letter, letter);

        letter++;
    }
    return 0;
}
