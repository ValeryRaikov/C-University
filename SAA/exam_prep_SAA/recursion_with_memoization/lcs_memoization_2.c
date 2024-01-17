// Demo program to implement the 3D memoization techniques

#include <stdio.h>
#include <string.h>

#define MAX 100

int arr[MAX][MAX][MAX];

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Returns length of LCS for X[0..m-1], Y[0..n-1], Z[0..o-1]
int lcs(char* X, char* Y, char* Z, int m, int n, int o) {
    // base case
    if (m == 0 || n == 0 || o == 0)
        return 0;

    // if the same state has already been computed
    if (arr[m - 1][n - 1][o - 1] != -1)
        return arr[m - 1][n - 1][o - 1];

    // if equal, then we store the value of the function call
    if (X[m - 1] == Y[n - 1] && Y[n - 1] == Z[o - 1]) {
        // store it in arr to avoid further repetitive work
        arr[m - 1][n - 1][o - 1] = 1 + lcs(X, Y, Z, m - 1, n - 1, o - 1);
        return arr[m - 1][n - 1][o - 1];
    } else {
        // store it in arr to avoid further repetitive work
        arr[m - 1][n - 1][o - 1] = max(lcs(X, Y, Z, m, n - 1, o),
                                       max(lcs(X, Y, Z, m - 1, n, o),
                                           lcs(X, Y, Z, m, n, o - 1)));
        return arr[m - 1][n - 1][o - 1];
    }
}

// Driver Code
int main() {
    memset(arr, -1, sizeof(arr));

    char X[] = "geeks";
    char Y[] = "geeksfor";
    char Z[] = "geeksforgeeks";

    int m = strlen(X);
    int n = strlen(Y);
    int o = strlen(Z);

    printf("Length of LCS is %d\n", lcs(X, Y, Z, m, n, o));
    // In this cas the word geeks is the lcs

    return 0;
}
