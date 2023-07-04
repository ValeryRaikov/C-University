#include <stdio.h>

int main()
{
    int size;
    printf("Enter array size:\n");
    scanf("%d", &size);
    int sequence[size];
    printf("Fill the array:\n");
    for(int i=0; i<size; ++i)
    {
        scanf("%d", &sequence[i]);
    }
    int true_condition = 1;
    for(int i=0; i<size; ++i)
    {
        if(i%2==1 && sequence[i] >= sequence[i-1])
        {
            true_condition = 0;
            break;
        }
        else if(i%2==0 && sequence[i] <= sequence[i-1])
        {
            true_condition = 0;
            break;
        }
    }
    if (true_condition)
    {
        printf("Sequence matches the condition.\n");
    }
    else
    {
        printf("Sequence does not match the condition.\n");
    }

    return 0;
}


