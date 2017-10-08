#include<iostream>
#include<cstdio>
#include<stdlib.h>



typedef struct DNode
{

    int data,freq;

    struct DNode *back,*next;

}DNode,*DoubleList;



InitDoubleList(DoubleList *DL)
{

    *DL=(DoubleList)malloc(sizeof(DNode));

    (*DL)->back=*DL;

    (*DL)->next=*DL;

}



void CreateDoubleList(DoubleList DL)
{

    DNode *rear,*s;

    int e;

    rear=DL;

    printf("Please enter a list divided by SPACE and ended by ENTER.\n");

    do{

        s=(DoubleList)malloc(sizeof(DNode));

        scanf("%d",&e);

        s->data=e;s->freq=0;s->back=rear;s->next=NULL;

        rear->next=s;rear=s;

    }while(getchar()!='\n');

}

void print(DoubleList L)
{

    DoubleList p=L->next;

    while(p->next){

        printf("%d(%d)\n",p->data,p->freq);

        p=p->next;

    }

    printf("%d(%d)\n",p->data,p->freq);

}

DoubleList Locate(DoubleList L,int x)
{

    DoubleList p=L->next,q;

    while(p->next){

        if(p->data==x){

            (p->freq)++;

            q=p->back;

            q->next=p->next;p->next->back=p->back;//取p

            while(q!=L&&p->freq>=q->freq)//向前找位置，>=以实现把最近操作的结点放到同频率结点离表头最近的位置
            {
                q=q->back;

            }

            p->back=q;p->next=q->next;//插入

            q->next=p;p->next->back=p;

            return p;

        }

        p=p->next;

    }

    return NULL;

}

int main()
{

    int i;

    DoubleList L,p;

    InitDoubleList(&L);

    CreateDoubleList(L);

    //p=Locate(L,2);Locate(L,2);Locate(L,3);Locate(L,2);

    for(i=0;i<2;i++)Locate(L,2);

    for(i=0;i<4;i++)Locate(L,3);

    for(i=0;i<4;i++)Locate(L,4);

    print(L);

    return 0;

}
