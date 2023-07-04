#include <stdio.h>

int main()
{
    int height = 5;
    int width = 10;
    int a;
    int b;
    char q = 'a';
    char symbol;

    printf("Choose a symbol: ");
    scanf("%c", &symbol);

    while (q != 'q')
    {

        for (a = 0;a < height;a++)
        {
                for (b = 0; b < width; b++)
                {

                    if((a==0)||(a==(height-1)))
                    {
                        printf("%c", symbol);
                    }
                    else
                    {
                         if((b==0) || (b==(width-1))) printf("%c", symbol);
                         else printf(" ");
                    }
                }
                printf("\n");

        }
        printf("\n\nEnter q to quit, or any other key to Continue:\n");
        scanf(" %c", &q);
    }
    return 0;
}
