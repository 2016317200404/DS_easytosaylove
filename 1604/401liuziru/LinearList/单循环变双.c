/*
    假设一个单循环链表，其结点含有三个域back、data、next 。
    其中data为数据域；back为指针域，它的值为空指针（ NULL）；
    next为指针域，它指向后继结点。请设计算法， 将此表改成双向循环链表。
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
        int data;
        struct Node *next,*back;
}Node,*LinkList;

InitCLinkList(LinkList *CL){
    *CL=(LinkList)malloc(sizeof(Node));
    (*CL)->back=NULL;
    (*CL)->data=-1;
    (*CL)->next=*CL;
}
void CreateCLinkList(LinkList CL){
    Node *rear,*s;
    int i;
    rear=CL;
    for(i=0;i<10;i++){
        s=(Node*)malloc(sizeof(Node));
        s->data=i;
        s->back=NULL;
        rear->next=s;
        rear=s;
    }
    rear->next=CL;
}

void StoDouble(LinkList CL){
    while(!CL->next->back){
        CL->next->back=CL;
        CL=CL->next;
    }
}

int main(){
    int i;
    LinkList L;
    InitCLinkList(&L);
    CreateCLinkList(L);
    StoDouble(L);

    printf("检验,利用back反向输出链表data：\n");
    L=L->back;
    for(i=0;i<11;i++){
        printf("%d ",L->data);
        L=L->back;
    }

    return 0;
}
