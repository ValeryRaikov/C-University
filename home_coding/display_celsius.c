#include <stdio.h>

int main()
{
    int fahr, celsius, start, end;
    printf("Enter start and end values:\n");
    scanf("%d %d", &start, &end);

    printf("Fahr-->Celsius\n");
    for(fahr = start; fahr<=end; fahr += 10)
    {
        celsius = 5*(fahr-32)/9;
        printf("%d\t%d\n", fahr, celsius);
    }

    return 0;
}
