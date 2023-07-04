#include <stdio.h>

int find_max(int a, int b)
{
    if (a>b)
        return a;
    else
        return b;
}

int find_min(int a, int b)
{
    if (a<b)
        return a;
    else
        return b;
}

int main ()
{
    int num, largest=0, smallest=0;
    printf("Enter number: \n");
    scanf("%d", &num);
    largest = smallest, num;
    while (num!=0)
    {
        printf("Enter number: \n");
        scanf("%d", &num);
        largest = find_max(largest, num);
        smallest = find_min(smallest, num);
    }
    printf("Result of max = %d\n", largest);
    printf("Result of min = %d\n", smallest);

    return 0;
}
