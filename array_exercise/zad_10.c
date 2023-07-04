#include <stdio.h>

void digits(int *a, int *b, int *c, int *d,int *e, int n)
{
    int *ptr_a;
    int *ptr_b;
    int *ptr_c;
    int *ptr_d;
    int *ptr_e;

    ptr_a = &a;
    ptr_b = &b;
    ptr_c = &c;
    ptr_d = &d;
    ptr_e = &e;

}

int main()
{
    int number;
    printf("Enter the number:\n");
    scanf("%d", &number);
    while (1)
    {
        if(number<=0)
        {
            printf("Number must be positive!\n");
            scanf("%d", &number);
        }
        else
            break;
    }
    int num[2];
    num[0]= number/10;
    num[1] =
    num[4]= number%10;

    digits(num[0], num[1], number);

    return 0;
}



