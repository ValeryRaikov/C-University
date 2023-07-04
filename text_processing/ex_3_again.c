#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 100

int main()
{
    char str[MAX_LEN];
    int i, j, count;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for (i = 0; str[i] != '\0'; i++)
    {
        count = 0;
        if (isalpha(str[i]))
        {
            for (j = 0; str[j] != '\0'; j++)
            {
                if (tolower(str[i]) == tolower(str[j]))
                {
                    count++;
                }
            }
            printf("%c: %d\n", tolower(str[i]), count);
        }
    }

    return 0;
}
