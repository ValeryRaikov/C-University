#include <stdio.h>

int main(void)
{
    char text1[100], text2[100];
    int i, flag = 0;

    printf("Enter text1: ");
    fgets(text1, sizeof(text1), stdin);

    printf("Enter text2: ");
    fgets(text2, sizeof(text2), stdin);

    for(i = 0; text1[i] != '\0' || text2[i] != '\0'; ++i)
    {
        if(text1[i] != text2[i])
        {
            flag = 1;
            break;
        }
    }

    if(!flag)
        printf("Both texts are equal");
    else
        printf("Texts are not equal");
}

