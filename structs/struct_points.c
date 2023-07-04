#include <stdio.h>
#include <math.h>

typedef struct
{
    int x;
    int y;
} Point;

int main()
{
    int number;
    printf("Number of points to be created:\n");
    scanf("%d", &number);

    Point p[number];
    for(int i=0; i<number; ++i)
    {
       printf("Enter coordinates x/y for p[%d]: ", i);
       scanf("%d %d", &p[i].x, &p[i].y);
    }

    printf("You created the following points:\n");
    for(int i=0; i<number; ++i)
    {
        printf("p[%d]=(%d, %d)\n", i, p[i].x, p[i].y);

        float side = sqrt(p[i].x*p[i].x + p[i].y*p[i].y);
        printf("Length of the side of point p[%d] and the center of the coordinate axis -> %.2f", i, side);
    }

    return 0;
}
