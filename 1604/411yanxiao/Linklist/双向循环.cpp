#include<iostream>
#include<cstdio>
#include<stdlib.h>

typedef struct DNode{

    int data;

    struct DNode *back,*next;

}DNode,*DoubleList;


InitDoubleList(DoubleList *DL){

    *DL=(DoubleList)malloc(sizeof(DNode));

    (*DL)->back=*DL;

    (*DL)->next=*DL;

}



void CreateDoubleList(DoubleList DL){

    DNode *rear,*s;

    int e;

    rear=DL;

    printf("Please enter a list divided by SPACE and ended by ENTER.\n");

    while(getchar()!='\n')
    {

        s=(DoubleList)malloc(sizeof(DNode));

        scanf("%d",&e);

        s->data=e;s->back=rear;s->next=DL;

        DL->back=s;rear->next=s;rear=s;
    }

}



/*order by asc*/

void unknown(DoubleList L)
{

    DoubleList p,q,r;

    p=L->next;q=p->next;r=q->next;

    while(q!=L)
    {

        while(p!=L&&p->data>q->data){

                p=p->back;

        }

        q->back->next=r;r->back=q->back;//连接q前后节点，即拿出q

        q->next=p->next;q->back=p;//将q插

        p->next=q;q->next->back=q;//在p后

        q=r;p=q->back;r=q->next;//为下一轮循环初始化

    }

}



void print(DoubleList L)
{

    DoubleList p=L->next;

    while(p!=L)
    {

        printf("%d ",p->data);

        p=p->next;

    }

}

void printback(DoubleList L)
{

    DoubleList p=L->back;

    while(p!=L)
    {

        printf("%d ",p->data);

        p=p->back;

    }

}



int main()
{

    DoubleList L;

    InitDoubleList(&L);

    CreateDoubleList(L);

    unknown(L);

    print(L);

    return 0;

}
