#include<stdio.h>

int main()
{
    int n, i, temp, pos, dir;
    printf("Enter array size:\n");
    scanf("%d", &n);
    int a[n];
    printf("Fill the array:\n");
    for(i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    printf("Enter the number of positions to shift:\n");
    scanf("%d", &pos);

    printf("Enter the direction of shifting:\n");
    printf("LEFT: 1 and RIGHT: 0\n");
    scanf("%d", &dir);

    while(pos)
    {
        if(dir)
        {
            temp = a[0];
            for(i = 0; i < n - 1; i++)
                a[i] = a[i + 1];

            a[n - 1] = temp;
        }
        else
        {
            temp = a[n - 1];
            for(i = n - 1; i > 0; i--)
                a[i] = a[i - 1];

            a[0] = temp;
        }

        pos--;
    }

    printf("Array after shift operation:\n");
    for(i = 0; i < n; i++)
        printf("%d\n", a[i]);

    printf("\n");

    return 0;
}
