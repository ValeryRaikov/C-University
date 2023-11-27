# include <stdio.h>

int moneti[] = {200, 100, 50, 20, 10, 5, 2, 1};
const int br = sizeof(moneti) / sizeof(moneti[0]);

void stotinki(int suma) {
    if (suma <= 0) {
        printf("Sumata e nevalidna");
        return;
    }
    int j = suma;
    for (int i=0; i<br; i++) {
        printf("Broi moneti po %d st. = %d\n", moneti[i], j/moneti[i]);

        j %= moneti[i];
    }
}

int main() {
    int suma;
    printf("Vyvedi suma: ");
    scanf("%d",&suma);
    stotinki(suma);

    return 0;
}
