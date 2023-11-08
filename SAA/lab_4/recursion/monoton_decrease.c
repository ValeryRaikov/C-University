#include <stdio.h>

int monoton(int num_arr[], int n) {
	int b;
	if(n == 1)
		return 1;
	if(num_arr[n-2] >= num_arr[n-1])
		b = 1;
	else
        b = 0;
	return b && monoton(num_arr, n-1);
}

int main() {
    int n;
    printf("Enter number of elements to store in the array: ");
    scanf("%d", &n);

    int num_arr[n];
    printf("Fill the array with %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num_arr[i]);
    }

    if (monoton(num_arr, n))
        printf("Array is monoton decreasing!\n");
    else
        printf("Array is NOT monoton decreasing!\n");

    printf("Array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d\t", num_arr[i]);
    }

    return 0;
}


