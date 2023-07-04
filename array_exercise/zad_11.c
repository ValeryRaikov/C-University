#include<stdio.h>
int main()
{
    int initial=0,final=500,a,b,c;
    printf("The Pythogorean Triplets in the given range are as follows:\n");
    for(a=initial;a<=final;a++){
        for(b=a;b<=final;b++){
            for(c=b;c<=final;c++){
                if(c*c==a*a+b*b){
                    printf("%d , %d , %d\n",a,b,c);
                }
            }
        }
    }
}
