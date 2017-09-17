#include<stdio.h>
#define MAX 10
typedef struct L
{
    int elem[MAX];
    int last ;
}L;
void swap(int*a,int*b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int main()
{
    L la={{1,2,3,4,5},4};
    int i,j;
    i=0;
    j=la.last;
    while(i!=j)
    {
        if(la.elem[i]%2==1)
            i++;
        else
        {
            if(la.elem[j]%2==1)
                swap(&la.elem[i],&la.elem[j]);
            else
                j--;
        }
    }
    for(i=0;i<=la.last;i++)
    {
        printf("%d ",la.elem[i]);
    }
    return 0;
}
