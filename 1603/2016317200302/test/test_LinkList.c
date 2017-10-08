#include<stdio.h>
#include"../List/LinkList.h"
int main()
{
    LinkList l;
    InitList(&l);
    int i = 0;
    for( ; i < 100 ; i ++)
    {
        CreateFromHead(l , i );
    }
    for( i = 0 ; i < 100 ; i ++)
    {
        CreateFromTail(l , i);
    }
    InseList(l , 10 , 1314);
    printf("%d\n" , FindList(l , 1314));
    PrintAll(l);
    return 0;
}
