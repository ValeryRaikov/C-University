#include <stdio.h>

int main()
{

    int age[5] = {18, 24, 26, 31, 19};

    int i;
    for (i = 0; i < 5; i++)
    {
        printf("%d age is %d\n", i+1, age[i]);
    }
    return 0;
}
