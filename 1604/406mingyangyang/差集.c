#include<stdio.h>
#define MAX 20
typedef struct L
{
    int elem[MAX];
    int last ;
}L;
int find(L l,int e)
{
    int i=0;
    while(i<=l.last&&l.elem[i]!=e)
    {
        i++;
    }
    if(i<=l.last)
        return i+1;
    else
        return 0;
}
void del(L *l,int i)
{
    int k;
    if(i<1||i>l->last+1)
    {
        printf("error");
    }
    for(k=i;k<=l->last;k++)
    {
        l->elem[k-1]=l->elem[k];
    }
    l->last--;
}
int main()
{
    L la={{25,34,57,50,16,48,9,63},8},lb={{12,50,23,79,4,34,25,13},8};
    int i;
    for(i=0;i<lb.last;i++)
    {
        int a;
        a=find(la,lb.elem[i]);
        if(a)
        {
            del(&la,a);
        }
    }
    for(i=0;i<la.last;i++)
    {
        printf("%d ",la.elem[i]);
    }
    return 0;
}
