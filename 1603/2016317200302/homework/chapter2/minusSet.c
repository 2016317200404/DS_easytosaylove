#include<stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../List/LinkList.h"


LinkList minusSet(LinkList la , LinkList lb)
{
    LinkList lc;
    InitList(&lc);
    int flag;
    Node *p , *s;
    p = la;
    s = lb;
    while(p->next != NULL)
    {
        p = p->next;
        s = lb;
        flag = 1;
        while(s->next != NULL)
        {
            s = s->next;
            if( p->data == s->data)
            {
                flag = 0;
                break;
            }
        }
        if(flag)CreateFromTail(lc , p->data);
    }
    return lc;
}

int main()
{
    int i;
    LinkList la , lb;
    InitList(&la);
    InitList(&lb);
    srand((unsigned)time(NULL));
    for( i = 0 ; i < 10 ; i ++)
    {
        CreateFromTail(la, rand()%20);
        CreateFromTail(lb , rand()%20);
    }
    PrintAll(la);
    PrintAll(lb);
    PrintAll(minusSet(la , lb));
    return 0;
}
