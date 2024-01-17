#include <stdio.h>
#include <string.h>

#define MAX 1000

int arr[MAX][MAX];

int max(int a, int b) {
    return (a > b) ? a : b;
}

int lcs(char* X, char* Y, int m, int n) {
    if (m == 0 || n == 0)
        return 0;

    // if the same state has already been computed
    if (arr[m - 1][n - 1] != -1)
        return arr[m - 1][n - 1];

    // if equal, then we store the value of the function call
    if (X[m - 1] == Y[n - 1]) {
        // store it in arr to avoid further repetitive work in future function calls
        arr[m - 1][n - 1] = 1 + lcs(X, Y, m - 1, n - 1);
        return arr[m - 1][n - 1];
    } else {
        // store it in arr to avoid further repetitive work in future function calls
        arr[m - 1][n - 1] = max(lcs(X, Y, m, n - 1), lcs(X, Y, m - 1, n));
        return arr[m - 1][n - 1];
    }
}

int main() {
    memset(arr, -1, sizeof(arr));

    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);

    printf("Length of LCS is %d\n", lcs(X, Y, m, n));

    return 0;
}
