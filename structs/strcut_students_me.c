#include <stdio.h>
#include <string.h>

void print_student(Students);

typedef struct
{
    char name[20];
    char id[10];
    int age;
    int grade;
} Students;

int main()
{
    int students_num, classes_num;
    printf("Enter number of classes:\n");
    scanf("%d", &classes_num);

    printf("Enter number of students per class:\n");
    scanf("%d", &students_num);

    Students student[students_num];

    char name[20], id[10];
    int age, grade;
    for(int i=0; i<classes_num; ++i)
    {
        for(int j=0; j<students_num; ++j)
        {
            printf("Enter student's name:\n");
            scanf("%s", &name);
            printf("Enter student's ID:\n");
            scanf("%s", &id);
            printf("Enter student's age:\n");
            scanf("%d", &age);
            printf("Enter student's grade:\n");
            scanf("%d", &grade);

            strcpy(student[j].name, name);
            strcpy(student[j].id, id);
            student[j].age = age;
            student[j].grade = grade;
        }
    }

    int sum_grades;
    float avg_res;
    for(int i=0; i<classes_num; ++i)
    {
        for(int j=0; j<students_num; ++j)
        {
            print_student(student[j]);
            sum_grades += student[j].grade;
        }
        avg_res = (float)sum_grades/students_num;

        printf("Average grade for class[%d] is: %.2f\n", i, avg_res);

        sum_grades = avg_res = 0;
    }


    return 0;
}

void print_student(Students student)
{
    printf("Student's information:\n");
    printf("Name: %s\nID: %s\nAge: %d\nGrade: %d\n", student.name, student.id, student.age, student.grade);
}
