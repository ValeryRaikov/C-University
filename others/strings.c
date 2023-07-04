#include <stdio.h>

int main()
{

    char text[] = "Valery";

    int i = 0;
    while (i < sizeof(text))
    {
        printf("%c", text[i]);
        i++;
    }

    return 0;
}
