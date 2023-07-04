#include <stdio.h>

int main()
{
    int size;
    printf("Enter array size:\n");
    scanf("%d", &size);
    int numbers[size];
    printf("Fill the array(Enter numbers in ascending order!):\n");
    for(int i=0; i<size; ++i)
    {
        scanf("%d", &numbers[i]);

    }
    int length = 1, max_length = 1, index = 0, start_index = 0;
    for(int i=1; i<size; ++i)
    {
        if(numbers[i] == numbers[i-1])
        {
            length++;
        }
        else
        {
            if(length > max_length)
            {
                max_length = length;
                start_index = index;
            }
            length = 1;
            index = i;
        }
    }

    printf("Most common number starts at index %d and exists %d times\n", start_index, max_length);

    return 0;
}
