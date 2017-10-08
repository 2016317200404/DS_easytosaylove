#include<stdio.h>
#include"../List/CircleLinkList.h"
int main()
{
    CLinkList l;
    InitCList(&l);
    int  i ;
    for( i = 0 ; i < 100 ; i ++)
    {
        CreateFromTailCList(l , i);
    }
   PrintAllC(l);
    return 0;
}
