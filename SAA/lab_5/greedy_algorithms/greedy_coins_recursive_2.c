#include <stdio.h>

int moneti[] = {200, 100, 50, 20, 10, 5, 2, 1};
const int br = sizeof(moneti) / sizeof(moneti[0]);

void stotinki(int suma, int index) {
    if (suma <= 0)
    printf("Sumata e nevalidna");
        return;

    if (index >= br)
        return;

    printf("Broi moneti po %d st. = %d\n", moneti[index], suma / moneti[index]);

    stotinki(suma % moneti[index], index + 1);
}

int main() {
    int sum;
    printf("Vyvedi suma: ");
    scanf("%d", &sum);
    stotinki(sum, 0);
    return 0;
}
