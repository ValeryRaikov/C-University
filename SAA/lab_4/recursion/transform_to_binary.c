#include <stdio.h>

int find_binary(int decimal) {
    if (decimal == 0)
       return 0;
    else
       return decimal % 2 + 10 * (find_binary(decimal / 2));
}

int main() {
    int dec_num;
    printf("Enter a number to transform: ");
    scanf("%d", &dec_num);

    int bin_num = find_binary(dec_num);
    printf("Binary of %d is %d", dec_num, bin_num);

    return 0;
}
