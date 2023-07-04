#include <stdio.h>

void print_person(char f_name[], char l_name[], int age)
{
    printf("Person information: %s %s -> %d\n", f_name, l_name, age);
}
void grades(float a, float b, float c, float d)
{
    printf("Results -> %.2f, %.2f, %.2f, %.2f\n", a, b, c, d);
    float avg_grade = (a+b+c+d) / 4.0;
    printf("Average grade -> %.2f\n", avg_grade);
}

int main()
{
    char first_name[20], last_name[20];
    int age;
    printf("Enter name and age:\n");
    scanf("%s %s %d", &first_name, &last_name, &age);
    print_person(first_name, last_name, age);

    float note1, note2, note3, note4;
    printf("Enter notes:\n");
    scanf("%f %f %f %f", &note1, &note2, &note3, &note4);
    grades(note1, note2, note3, note4);

    return 0;
}
