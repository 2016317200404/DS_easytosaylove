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
    int i;
    rear=L;
    for(i=1;i<=20;i++){
        s=(Node*)malloc(sizeof(Node));
        s->data=i;
        rear->next=s;
        rear=s;
    }
    rear->next=NULL;
}
void Print(LinkList L){
    L=L->next;
    while(L){
        printf("%d ",L->data);
        L=L->next;
    }
    printf("\n");
}

void Func(LinkList L){
    LinkList p,q;
    q=p=L->next->next;
    L->next->next=NULL;
    while(q){
        q=q->next;
        p->next=L->next;
        L->next=p;
        p=q;
    }
}
int main(){
    LinkList L;
    InitLinkList(&L);
    CreateLinkList(L);
    Print(L);
    Func(L);
    Print(L);
    return 0;
}
