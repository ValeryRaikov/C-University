#include <stdio.h>
#include <string.h>

int count_vowels(char str[])
{
    int i, count=0;

    for(i = 0; i < strlen(str); ++i)
    {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
            count++;
    }

    return count;
}

int main(void)
{
    char text[100];

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    int vowels_count = count_vowels(text);
    printf("Count of vowels in text is: %d", vowels_count);
}
