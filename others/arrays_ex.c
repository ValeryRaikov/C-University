#include <stdio.h>
#include <string.h>

int main ()
{
    char name[] = "Valery";
    printf("%s\n", name);

    char input_name[30];
    printf("Enter name: ");

    //scanf("%s", &input_name);

    fgets(input_name, 30, stdin);
    printf("User name is: %s\n", input_name);

    int i;
    for (i=0; i<strlen(input_name); ++i)
    {
        printf("%c\n", input_name[i]);
    }

    int counter = 0;
    while (input_name[counter]!= 0)
    {
        printf("%c\n", input_name[counter]);
        counter ++;
    }

    int numbers[5] = {2, 3, 5, 7, 10};

    int* pointer = &numbers;
    printf("Address of the array is: %p\n", pointer);
    printf("First number of the array is: %d\n", *pointer);

    double num = 5.369452;
    double* ptr = &num;

    printf("%.2lf --> %.2lf\n", *ptr, num);
    printf("%p --> %p\n", ptr, &num);

    printf("Value is %.2lf; Address is %p\n", *ptr, ptr);

    return 0;
}
