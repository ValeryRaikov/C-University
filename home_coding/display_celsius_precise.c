#include <stdio.h>

int main()
{
    int start, end;
    float fahr, celsius;
    printf("Enter start and end values:\n");
    scanf("%d %d", &start, &end);

    fahr = (float)start;
    printf("Fahr-->Celsius\n");
    while (fahr<=end)
    {
        celsius = (5.0/9.0)*(fahr-32.0);
        printf("%.2f\t%.2f\n", fahr, celsius);

        fahr += 10.0;
    }

    return 0;
}
