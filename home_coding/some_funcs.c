#include <stdio.h>

int add(int, int);
int check_if_valid(int, int[10]);

void main()
{
    int num1, num2;
    printf("Enter 2 numbers:\n");
    scanf("%d %d", &num1, &num2);
    int result = add(num1, num2);
    printf("%d+%d=%d\n", num1, num2, result);

    int num, nums[10];
    printf("Enter number to check:\n");
    scanf("%d", &num);
    printf("Fill the array:\n");
    for(int i=0; i<10; ++i)
    {
        scanf("%d", &nums[i]);
    }
    int check = check_if_valid(num, nums);
    printf("Output: %d", check);
}

int add(int a, int b)
{
    return a+b;
}

int check_if_valid(int a, int numbers[10])
{
    int check = 0;
    for(int i=0; i<10; ++i)
    {
        if(numbers[i] == a)
        {
            check = 1;
            printf("Yes, %d exists.\n", a);
            return a;
        }
    }
    if(!check)
        {
        printf("No, %d does not exist.\n", a);
        }
    return 0;
}
