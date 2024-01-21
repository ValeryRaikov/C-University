#include <stdio.h>

int main() {
    printf("Create your 3D array:");

    int a, b, c;
    printf("Enter dimensions sizes: (a, b, c):\n");
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    int arr[a][b][c];
    for (int i=0; i<a; i++) {
        for (int j=0; j<b; j++) {
            for (int k=0; k<c; k++) {
                printf("arr[%d][%d][%d] = ", i, j, k);
                scanf("%d", &arr[i][j][k]);
            }
        }
    }

    printf("This is the 3D array you created:\n");
    for (int i=0; i<a; i++) {
        for (int j=0; j<b; j++) {
            for (int k=0; k<c; k++) {
                printf("%d ", arr[i][j][k]);
            }
            printf("\n");
        }
    }

    return 0;
}