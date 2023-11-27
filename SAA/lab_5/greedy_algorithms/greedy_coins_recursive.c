// Problems with this solution

#include <stdio.h>
#include <limits.h>

int coins[] = {200, 100, 50, 20, 10, 5, 2, 1};
int numCoins = sizeof(coins) / sizeof(coins[0]);

int minCoins(int amount) {
    if (amount == 0) {
        return 0;
    }

    int result = INT_MAX;

    for (int i = 0; i < numCoins; i++) {
        if (coins[i] <= amount) {
            int subResult = minCoins(amount - coins[i]);

            if (subResult != INT_MAX && subResult + 1 < result) {
                result = subResult + 1;
            }
        }
    }

    return result;
}

int main() {
    int amount;

    printf("Enter the amount: ");
    if (scanf("%d", &amount) != 1 || amount < 0) {
        printf("Invalid input. Please enter a non-negative integer.\n");
        return 1;
    }

    printf("Minimal amount of coins for %d: %d\n", amount, minCoins(amount));

    return 0;
}
