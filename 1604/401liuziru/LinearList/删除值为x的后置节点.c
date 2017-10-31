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
int Delete(LinkList L,int x){
    LinkList p=L->next;
    while(p){
        if(p->next==NULL)break;
        if(p->data==x){
            p->next=p->next->next;
            return 1;
        }
        p=p->next;
    }
    return 0;
}
int main(){
    int x;
    LinkList L;
    InitLinkList(&L);
    CreateLinkList(L);
    Print(L);
    scanf("%d",&x);
    if(Delete(L,x))Print(L);
    else printf("Error!");
    return 0;
}
