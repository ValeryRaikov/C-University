#include <stdio.h>

int coins_arr[] = {1, 2, 5, 10, 20, 50, 100};

int main() {
    int price;
    printf("Enter the price to calculate: ");
    scanf("%d", &price);

    int sum = 0;
    int num_coins = 0;
    for (int i = sizeof(coins_arr) / sizeof(coins_arr[0]) - 1; i >= 0; i--) {
        while (sum + coins_arr[i] <= price) {
            sum += coins_arr[i];
            num_coins++;
        }
    }

    printf("Total number of coins to pay %d is %d", price, num_coins);

    return 0;
}