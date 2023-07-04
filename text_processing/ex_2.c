#include <stdio.h>
#include <string.h>

int main(void) {
    char text[100];
    int i, word_count = 0;

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    for(i = 0; i < strlen(text); ++i) {
        if(text[i] == ' ' || text[i] == '\n' || text[i] == '\t' || text[i] == '\0') {
            word_count++;
        }
    }
    printf("Number of words in text is: %d", word_count);
}
