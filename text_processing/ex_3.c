#include <stdio.h>
#include <string.h>

int main(void)
{
    char text[100], chr;
    int i, freq = 0;

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter a character: ");
    scanf("%c", &chr);

    for(i = 0; i < strlen(text); ++i)
    {
        if(text[i] == chr)
        {
            freq++;
        }
    }
    printf("Frequency of %c = %d", chr, freq);
}
