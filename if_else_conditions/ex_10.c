#include <stdio.h>

int main()
{
    int n;
    printf("Enter number count:\n");
    scanf("%d", &n);

    int number, p1, p2, p3, p4, p5;
    for (int i=0; i<n; ++i)
    {
        printf("Enter number:\n");
        scanf("%d", &number);

        if (number>=800)
            p5+=1;
        else if (number>=600)
            p4+=1;
        else if (number>=400)
            p3+=1;
        else if (number>=200)
            p2+=1;
        else
            p1+=1;
    }
    printf("p1 percentage=%.2f\n", (p1/n)*100);
    printf("p2 percentage=%.2f\n", (p2/n)*100);
    printf("p3 percentage=%.2f\n", (p3/n)*100);
    printf("p4 percentage=%.2f\n", (p4/n)*100);
    printf("p5 percentage=%.2f\n", (p5/n)*100);

    return 0;
}
