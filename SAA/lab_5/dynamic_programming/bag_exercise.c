#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 30
#define MAXM 1000
char set[MAXM][MAXN];
/* set[i][j]==1 means that for capacity i an optimal solution contains item j */
unsigned int Fn[MAXM]; /* objective function */
unsigned int m[MAXN] = {0, 30, 15, 50, 10, 20, 40, 5, 65}; /* volume */
unsigned int c[MAXN] = {0,  5,  3,  9,  1,  2,  7, 1, 12}; /* price */
unsigned int M = 70; /* actual capacity */
unsigned int N = 8;  /* number of items */

void calculate() {
    unsigned int maxValue, maxIndex, i, j;
    memset(set, 0, sizeof(set));

    for (i = 1; i <= M; i++) {
        maxValue = maxIndex = 0;
        for (j = 1; j <= N; j++) {
            if (m[j] <= i && !set[i - m[j]][j])
                if (c[j] + Fn[i - m[j]] > maxValue) {
                    maxValue = c[j] + Fn[i - m[j]];
                    maxIndex = j;
                }
        }
        if (maxIndex > 0) {
            Fn[i] = maxValue;
            memcpy(set[i], set[i - m[maxIndex]], N);
            set[i][maxIndex] = 1;
        }
        if (Fn[i] < Fn[i - 1]) {
            Fn[i] = Fn[i - 1];
            memcpy(set[i], set[i - 1], N);
        }
    }
}

void write() {
    for (int i = 1; i <= N; i++)
        if (set[M][i])
            printf("%4d ", i);
    printf("\n");
    printf("Max value: %u\n", Fn[M]);
}

void read() {
    scanf("%u %u", &M, &N);
    for (int i = 1; i <= N; i++)
        scanf("%u", &m[i]);
    for (int i = 1; i <= N; i++)
        scanf("%u", &c[i]);
}

int main() {
    calculate();
    write();

    return 0;
}
