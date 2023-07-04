#include <stdio.h>

int main()
{
    int rows, cols;
    printf("Enter rows and columns:\n");
    scanf("%d %d", &rows, &cols);
    int arr[rows][cols];
    printf("Create your matrix:\n");
    for(int i=0; i<rows; ++i)
    {
        for(int j=0; j<cols; ++j)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("Displaying the matrix:\n");
    for(int i=0; i<rows; ++i)
    {
        for(int j=0; j<cols; ++j)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("Another display type:\n");
    int *ptr = &arr[0][0];
    int total = rows * cols;
    for(int i=0; i<total; ++i)
    {
        if((i+1)%cols==0)
            printf("%d\n", *(ptr+i));
        else
            printf("%d ", *(ptr+i));
    }

    return 0;
}
