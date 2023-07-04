#include <stdio.h>
#include <string.h>

void uppercase(char *str);

int main() {
    char text[100];

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    uppercase(text);

    printf("Text in uppercase: %s\n", text);

    return 0;
}

void uppercase(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 'a' + 'A';
        }
    }
}

