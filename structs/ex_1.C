#include <stdio.h>
#include <math.h>

typedef struct
{
    int x;
    int y;
    int z;
} Point;

int main()
{
    int number;
    printf("Number of points to be created:\n");
    scanf("%d", &number);

    Point p[number];
    for(int i=0; i<number; ++i)
    {
       printf("Enter coordinates x/y/z for p[%d]: ", i);
       scanf("%d %d %d", &p[i].x, &p[i].y, &p[i].z);
    }

    printf("You created the following points:\n");
    for(int i=0; i<number; ++i)
    {
        printf("p[%d]=(%d, %d, %d)\n", i, p[i].x, p[i].y, p[i].z);

        float side = sqrt(p[i].x*p[i].x + p[i].y*p[i].y + p[i].z*p[i].z);
        printf("Length of the side of point p[%d] and the center of the coordinate axis -> %.2f\n", i, side);
    }

    return 0;
}

