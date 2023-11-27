#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000

int main()
{
    int i, a[N];

    srand((unsigned)time(NULL));

    clock_t cl;
    cl = clock();

    for (i = 0; i < N; i++)
        a[i] = rand() % 100;

    printf("Sorting ...\n");

    // Example with the bubble sort algorithm
    for (i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    cl = clock() - cl;
    printf("Time: %f sec.\n", (double)cl / CLOCKS_PER_SEC);

    return 0;
}
