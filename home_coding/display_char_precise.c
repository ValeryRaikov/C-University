#include <stdio.h>

void main()
{
    int i=0, num, numbers[5];

    printf("Enter numbers != 0\n");
    while(i<5)
    {
        scanf("%d", &num);
        if(num == 0)
            break;

        while(num<0 || num>100)
        {
            printf("Number out of range!");
            scanf("%d", &num);
        }
        numbers[i] = num;
        printf("%d\n", numbers[i]);
        ++i;
    }
}
