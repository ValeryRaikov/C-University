#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[30];
    char id[10];
    int age;
    int grades[3];
} Students;

void print_students(Students *student, int class_size);

int main()
{
    int size;
    printf("Enter the total number of students: ");
    scanf("%d", &size);

    Students student[size];
    char name[30], id[10];
    for (int i=0; i<size; ++i)
    {
        printf("Enter information for student[%d]:\n", i+1);
        getchar();
        fgets(name, sizeof(name), stdin);
        strcpy(student[i].name, name);
        scanf("%s", id);
        strcpy(student[i].id, id);
        scanf("%d", &student[i].age);
        for (int j=0; j<3; ++j)
            scanf("%d", &student[i].grades[j]);
    }

    print_students(student, size);

    return 0;
}

void print_students(Students *student, int class_size)
{
    printf("Students info:\n");
    for (int i=0; i<class_size; ++i)
    {
        printf("Student %s with ID: %s, age: %d\n", student[i].name, student[i].id, student[i].age);
        printf("Grades:\n");
        for (int j=0; j<3; ++j)
            printf("%d\n", student[i].grades[j]);
    }
}
