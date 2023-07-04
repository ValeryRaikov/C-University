#include <stdio.h>

int main ()
{
    int x, y;
    printf("Enter x, y:\n");
    scanf("%d %d", &x, &y);

    int x1,x2,y1,y2;
    int escape=0;
    while (!escape){
        printf("Enter x1, x2:\n");
        scanf(" %d", &x1);
        scanf(" %d", &x2);
        if (x2<x1){
            printf("x2 should be bigger than x1. Enter new x2\n");
            scanf(" %d", &x2);
        }
        printf("Enter y1, y2:\n");
        scanf(" %d", &y1);
        scanf(" %d", &y2);
        if (y2<y1){
            printf("y2 should be bigger than y1. Enter new y2\n");
            scanf("%d", &y2);
        }
        escape=1;

    }
    printf("x=%d, y=%d, x1=%d, x2=%d, y1=%d, y2=%d\n",x,y,x1,x2,y1,y2);

    if ((x>=x1 && x<=x2) && (y>=y1 && y<=y2))
        printf("Inside\n");
    else
    printf("Outside\n");

    return 0;
}
