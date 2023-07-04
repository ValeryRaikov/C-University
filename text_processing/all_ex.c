#include <stdio.h>

int stringLength(char str[]) {
   int i;

   for(i = 0; str[i] != '\0'; i++);

   return i;
}

int main() {
   char str[100];

   printf("Enter a string: ");
   scanf("%s", str);

   int len = stringLength(str);
   printf("Length of string: %d", len);

   return 0;
}

#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, wordCount=0;

    printf("Enter a string: ");
    gets(str);

    for(i=0; i<strlen(str); i++) {
        if(str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            wordCount++;
        }
    }
    printf("Number of words in string: %d", wordCount+1);

    return 0;
}

#include <stdio.h>
#include <string.h>

int main() {
    char str[100], ch;
    int i, freq=0;

    printf("Enter a string: ");
    gets(str);

    printf("Enter a character to find frequency: ");
    scanf("%c", &ch);

    for(i=0; i<strlen(str); i++) {
        if(str[i] == ch) {
            freq++;
        }
    }
    printf("Frequency of %c = %d", ch, freq);

    return 0;
}

#include <stdio.h>

int main() {
    char str1[100], str2[100];
    int i, flag = 0;

    printf("Enter first string: ");
    gets(str1);

    printf("Enter second string: ");
    gets(str2);

    for(i=0; str1[i]!='\0' || str2[i]!='\0'; i++) {
        if(str1[i] != str2[i]) {
            flag = 1;
            break;
        }
    }

    if(flag == 0) {
        printf("Both strings are equal");
    } else {
        printf("Strings are not equal");
    }

    return 0;
}

#include <stdio.h>
#include <string.h>

int countVowels(char str[]) {
    int i, count=0;

    for(i=0; i<strlen(str); i++) {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
           str[i] == 'o' || str[i] == 'u' || str[i] == 'A' ||
           str[i] == 'E' || str[i] == 'I' || str[i] == 'O' ||
           str[i] == 'U') {
            count++;
        }
    }

    return count;
}

#include <stdio.h>
#include <string.h>

void toUpperCase(char *str);

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    toUpperCase(str);

    printf("String in uppercase: %s\n", str);

    return 0;
}

void toUpperCase(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }
}
