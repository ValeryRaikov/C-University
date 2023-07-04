#include <stdio.h>

#define MAX_STUDENTS 50
#define MAX_CLASSES 10

typedef struct
{
    char name[20];
    char id[10];
    float grade;
} Student;

typedef struct
{
    char name[30];
    int num_students;
    Student students[MAX_STUDENTS];
} Class;

typedef struct
{
    int num_classes;
    Class classes[MAX_CLASSES];
} School;

float calculate_average_grade_school(School school)
{
    float total_grade;
    int total_students;

    for (int i=0; i<school.num_classes; ++i)
    {
        for (int j=0; j<school.classes[i].num_students; ++j)
        {
            total_grade += school.classes[i].students[j].grade;
            total_students++;
        }
    }
        return total_grade / total_students;
}

int main()
{
    School school = {0};

    Class class1 = {"Math", 2, {
        {"Pesho", "123456789", 90},
        {"Gosho", "111234555", 80}
    }};
    Class class2 = {"Science", 3, {
        {"Ivan", "987654321", 70},
        {"Stamat", "192837465", 60},
        {"Mitio", "918273645", 50}
    }};

    school.classes[0] = class1;
    school.classes[1] = class2;
    school.num_classes = 2;

    float average_grade_school = calculate_average_grade_school(school);
    printf("Average grade for the whole school is: %.2f\n", average_grade_school);

    return 0;
}
