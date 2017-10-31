#include<stdio.h>
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
    do{
        s=(DoubleList)malloc(sizeof(DNode));
        scanf("%d",&e);
        s->data=e;s->back=rear;s->next=DL;
        DL->back=s;rear->next=s;rear=s;
    }while(getchar()!='\n');
}

/*order by asc*/
void Sort(DoubleList L){
    DoubleList p,q,r;
    p=L->next;q=p->next;r=q->next;
    while(q!=L){
        while(p!=L&&p->data>q->data){
                p=p->back;
        }
        q->back->next=r;r->back=q->back;//连接q前后节点，即拿出q
        q->next=p->next;q->back=p;//将q插
        p->next=q;q->next->back=q;//在p后
        q=r;p=q->back;r=q->next;//为下一轮循环初始化
    }
}

void print(DoubleList L){
    DoubleList p=L->next;
    printf("----------");
    while(p!=L){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
void printback(DoubleList L){
    DoubleList p=L->back;
    while(p!=L){
        printf("%d ",p->data);
        p=p->back;
    }
}

void Do(DoubleList L){
    int n,i,e,x;
    int j;
    DoubleList p,s;
    scanf("%d",&n);//n为接受命令的行数
    for(j=0;j<n;j++){
        scanf("%d",&x);
        p=L;
        if(x==1){   //添加
            scanf("%d%d",&i,&e);
            while(i){
                p=p->next;
                --i;

            }
            s=(DoubleList)malloc(sizeof(DNode));
            s->data=e;
            s->next=p;s->back=p->back;
            s->back->next=s;s->next->back=s;

        }
        else if(x==2){  //删除
            scanf("%d",&i);
            while(i){
                p=p->next;
                --i;
            }
            if(p->next!=L){
                p->back->next=p->next;
                p->next->back=p->back;
                free(p);
            }

        }
        else if(x==0) print(L);
        else return ;
    }
}
int main(){
    DoubleList L;
    InitDoubleList(&L);
    Do(L);
    return 0;
}

/*
sample input:
12
1 1 2
0
1 2 7
0
2 1
0
1 2 4
1 3 5
1 2 6
0
2 3
0

sample output:
2
2 7
7
7 6 4 5
7 6 5
*/
