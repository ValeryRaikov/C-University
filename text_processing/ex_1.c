#include <stdio.h>

int str_len(char str[])
{
    int i = 0;

    while(1)
    {
        if(str[i] == '\0')
            break;
        else
            i++;
    }

    return i;
}

int main(void)
{
    char text[100];

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    int len = str_len(text);
    printf("Count of words in text is: %d", len-1);
}
