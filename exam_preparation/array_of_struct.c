#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x;
    int y;
    int z;
} Point;

int main()
{
    int total;
    printf("Enter total number of points: ");
    scanf("%d", &total);

    Point *array = (Point*)calloc(total, sizeof(Point));

    for (int i=0; i<total; ++i)
    {
        printf("Enter coordinates x/y/z for point(%d): ", i+1);
        scanf("%d %d %d", &array[i].x, &array[i].y, &array[i].z);
    }
    printf("Points:\n");
    for (int i=0; i<total; ++i)
    {

        printf("P(%d): x-%d y-%d z-%d\n", i+1, array[i].x, array[i].y, array[i].z);
    }

    free(array);

    return 0;
}
