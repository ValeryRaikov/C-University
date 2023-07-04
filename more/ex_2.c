#include <stdio.h>

int main()
{
    int n;
    printf("Enter array size:\n");
    scanf("%d", &n);
    int sequence[n];
    for(int i=0; i<n; ++i)
    {
        scanf("%d", sequence[i]);
    }
    int true_condition = 1;
    for(int i =0; i<n; ++i)
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

