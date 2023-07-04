#include <stdio.h>
#include <string.h>

typedef struct
    {
        char name[20];
        char id[10];
        int age;
        int grades[5];
    } Student;

void print_student(Student);
float calculate_avg(Student);

int main()
{
    //Valery...
    Student Valery;

    strcpy(Valery.name, "Valery");
    strcpy(Valery.id, "121222139");
    Valery.age = 19;

    printf("Enter student's grades:\n");
    for(int i=0; i<5; ++i)
        scanf("%d", &Valery.grades[i]);

    print_student(Valery);

    putchar('\n');

    float average = calculate_avg(Valery);
    printf("%s's average result is: %.2f\n", Valery.name, average);

    putchar('\n');

    //Ivan...
    Student student2;
    char name[20], id[10];
    int age;
    int grades[5];
    printf("Enter student's name:\n");
    scanf("%s", &name);
    printf("Enter student's ID:\n");
    scanf("%s", &id);
    printf("Enter student's age:\n");
    scanf("%d", &age);
    printf("Enter student's grades:\n");
    for(int i=0; i< 5; ++i)
    {
        scanf("%d", &student2.grades[i]);
    }

    //Create Ivan...
    strcpy(student2.name, name);
    strcpy(student2.id, id);
    student2.age = age;

    print_student(student2);
    calculate_avg(student2);


    return 0;
}

void print_student(Student student)
{
    printf("Student information:\n");

    printf("Name->%s\nID->%s\nAge->%d\n", student.name, student.id, student.age);

    printf("Grades:\n");
    for(int i=0; i<5; ++i)
    {
        printf("%d ", student.grades[i]);
    }
}

float calculate_avg(Student student)
{
    float sum, avg;

    for(int i=0; i<5; ++i)
        sum += student.grades[i];

    avg = sum/5;

    printf("Average: %.2f\n", avg);

    return avg;
}
