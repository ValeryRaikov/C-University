#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
int previous_len=0, start=0, c[10], len=0;
int a[] = {1, 3, 5, 1, 5, 7, 8, 9, 10, 11, 12};
for (int i = 0; i < (sizeof(a)/sizeof(int)); ++i)
    {
    if(a[i+1] > a[i])
    {
        len++;
        if (len > previous_len)
        {
            previous_len=len;
            start=i+1-len;
        }
    } else
    {
        previous_len=len;
        len=0;
    }
}
printf("Longest streak is:\n");
for(int i = 0; i <= previous_len; ++i)
{
    c[i]=a[start+i];
    printf("%d ",c[i]);

}
return 0;
}
