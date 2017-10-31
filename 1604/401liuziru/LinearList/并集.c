#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
        int data;
        struct Node *next;
}Node,*LinkList;

InitLinkList(LinkList *L){
    *L=(LinkList)malloc(sizeof(Node));
    (*L)->next=NULL;
}
void CreateLinkList(LinkList L){
    Node *rear,*s;
    int x;
    rear=L;
    do{
        s=(Node*)malloc(sizeof(Node));
        scanf("%d",&x);
        s->data=x;
        rear->next=s;
        rear=s;
    }while(getchar()!='\n');
    rear->next=NULL;
}
void Print(LinkList L){
    LinkList p=L->next;
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
void Func(LinkList la,LinkList lb,LinkList lc){
    LinkList pa=la->next,pb=lb->next;
    LinkList rear=lc;
    LinkList p;
    int flag;
    while(pa||pb){
        if(pa->data==pb->data){  //la，lb两个节点数值相等，则不可能与lc已存在项重复
            rear->next=pa;
            pa=pa->next;pb=pb->next;
            rear=rear->next;rear->next=NULL;
        }
        else{
            p=lc;
            while(p){  //遍历lc，寻找可能的重复项
                if(pa->data==p->data)flag=1;
                if(pb->data==p->data)flag=2;
                p=p->next;
            }
            if(flag==1){
                pa=pa->next;
                rear->next=pb;
                pb=pb->next;
                rear=rear->next;
                rear->next=NULL;
            }
            else if(flag==2){
                pb=pb->next;
                rear->next=pa;
                pa=pa->next;
                rear=rear->next;
                rear->next=NULL;
            }
            else{
                rear->next=pa;pa=pa->next;rear=rear->next;
                rear->next=pb;pb=pb->next;rear=rear->next;
                rear->next=NULL;
            }

        }
    }
}

int main(){
    LinkList la,lb,lc;
    InitLinkList(&la);InitLinkList(&lb);InitLinkList(&lc);
    CreateLinkList(la);CreateLinkList(lb);
    Func(la,lb,lc);
    Print(lc);
    return 0;
}
