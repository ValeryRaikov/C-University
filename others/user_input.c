#include <stdio.h>

int main() {

int num_1;
int num_2;

    printf("Enter value for number_1: \n");
    scanf("%d", &num_1);
    printf("Enter value for number_2: \n");
    scanf("%d", &num_2);

    printf("number_1 = %d, number_2 = %d\n", num_1, num_2);

    if (num_1 > num_2){
        printf("%d > %d", num_1, num_2);
    } else if (num_1 < num_2) {
        printf("%d < %d", num_1, num_2);
    } else {
        printf("%d = %d", num_1, num_2);
    }

return 0;
}
