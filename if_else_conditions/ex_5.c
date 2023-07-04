#include <stdio.h>

int main ()
{
    int t1, t2, t3;
    printf("Enter times\n");
    scanf("%d %d %d", &t1, &t2, &t3);

    int time_sec = t1+t2+t3;
    int mins = time_sec / 60;
    int secs = time_sec - (mins*60);

    if (secs < 10)
        printf("Time: %d:0%d", mins, secs);
    else
        printf("Time: %d:%d", mins, secs);

    return 0;
}
