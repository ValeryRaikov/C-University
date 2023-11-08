#include <stdio.h>

int search(int num_arr[], int x, int n) {
	if(n < 1)
		return num_arr[0] == x;
	return x == num_arr[n-1] || search(num_arr, x, n-1);
}

int main() {
    int n, number;
    printf("Enter number of elements to store in the array: ");
    scanf("%d", &n);

    int num_arr[n];
    printf("Fill the array with %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num_arr[i]);
    }

    printf("Enter your number: ");
    scanf("%d", &number);

    if (search(num_arr, number, n))
        printf("Element found in the array!");
    else
        printf("Element NOT found in the array!");

    return 0;
}

