#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int previous_len=0, start=0, len=0;
    int size;
    printf("Enter array size:\n");
    scanf("%d", &size);
    int arr[size], new_arr[size];
    printf("Fill the array:\n");
    for(int i=0; i<size; ++i)
    {
        scanf("%d", &arr[i]);
    }

    for (int i=0; i<(sizeof(arr)/sizeof(int)); ++i)
    {
        if(arr[i+1] > arr[i])
        {
            len++;
            if (len > previous_len)
            {
                previous_len=len;
                start=i+1-len;
            }
        }
        else
        {
            previous_len=len;
            len=0;
        }
    }
    printf("Longest streak is:\n");
    for(int i=0; i<=previous_len; ++i)
    {
        new_arr[i]=arr[start+i];
        printf("%d ",new_arr[i]);
    }

    return 0;
}

