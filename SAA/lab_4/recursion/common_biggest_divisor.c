#include <stdio.h>

int min(int p, int q) {
	if (p > q)
		return q;
	else
		return p;
}

int nod(int c, int d) {
	if( c == d)
		return c;
	else
		return nod(abs(c-d), min(c,d));
}

int main() {
    int a, b;

    printf("Enter number a: ");
    scanf("%d", &a);
    printf("Enter number b: ");
    scanf("%d", &b);

    int result = nod(a, b);
    printf("NOD = %d", result);

    return 0;
}
