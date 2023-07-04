#include <stdio.h>
#include <string.h>

int main()
{
    char name[10] = "Valery";
    char test_name[10] = "Valery";
    char first_letter = 'V';

    if (name[0] == first_letter)
        printf("Yes!");
    else
        printf("No!");

    putchar('\n');

    //Incorrect!
    /*if (name == test_name)
        printf("Yes!");
    else
        printf("No!");*/

    //Correct!
    if (strcmp(name, test_name)==0)
        printf("Yes!");
    else
        printf("No!");

    return 0;
}
