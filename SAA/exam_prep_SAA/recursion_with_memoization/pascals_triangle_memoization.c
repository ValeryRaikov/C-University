#include <stdio.h>

#define MAX 100

struct Pair {
    int first;
    int second;
};

int cache[MAX][MAX];

int getPascalValue(int c, int r) {
    if (cache[c][r] != -1) {
        return cache[c][r];
    }

    if (c == 0 || c == r) {
        cache[c][r] = 1;
        return 1;
    }

    cache[c][r] = getPascalValue(c, r - 1) + getPascalValue(c - 1, r - 1);
    return cache[c][r];
}

int pascal(int c, int r) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cache[i][j] = -1;
        }
    }

    cache[0][0] = 1;

    for (int i = 1; i <= r; i++) {
        cache[0][i] = 1;
        cache[i][i] = 1;
    }

    return getPascalValue(c, r);
}

int main() {
    int c = 5;
    int r = 7;

    int result = pascal(c, r);

    printf("Pascal's value for (%d, %d) is %d\n", c, r, result);

    return 0;
}
