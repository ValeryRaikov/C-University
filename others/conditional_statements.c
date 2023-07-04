#include <stdio.h>
#include <stdbool.h>

int main() {
    int a = 10;
    int b = 10;

    if (a > b){
        printf("a is greater than b");
    } else if (b > a) {
        printf("b is greater than a");
    } else {
        printf("a equals b");
    }
    return 0;
}
