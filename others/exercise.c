#include <stdio.h>

int main() {

int a, b, c;

printf("Enter the value of the numbers a, b, c: \n");
scanf("%d %d %d", &a, &b, &c );

printf("\nNumber a = %d", a);
printf("\nNumber b = %d", b);
printf("\nNumber c = %d", c);

int add = a+b+c;
int sub = a-b-c;
int mul = a*b*c;
int div = a/b/c;

printf("\nAddition: %d", add);
printf("\nSubtraction: %d", sub);
printf("\nMultiplication: %d", mul);
printf("\nDivision: %d", div);

return 0;
}
