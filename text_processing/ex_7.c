#include <stdio.h>
#include <string.h>

void lowercase(char *str);

int main() {
    char text[100];

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    lowercase(text);

    printf("Text in uppercase: %s\n", text);

    return 0;
}

void lowercase(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
    }
}

