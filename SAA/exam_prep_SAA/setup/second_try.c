#include <stdio.h>

int main() {
    printf("This is the second test:\n");

    char name[20];

    printf("Enter your name: ");
    scanf("%s", name);
    printf("Hello, %s", name);

    printf("\nWe are ready for work:)\n");

    return 0;
}