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
}
void Do(LinkList L){
    LinkList q=L,p;//q为奇针，定位；p为偶针，保存前插节点
    while(1){
        q=q->next;
        if(!q) break;
        p=q->next;//初始化放在下一轮的开头，在循环体内解决最后一个节点的移动
        q->next=p->next;//断p
        p->next=L->next;L->next=p;//头插p
    }
}
int main(){
    LinkList L;
    InitLinkList(&L);
    CreateLinkList(L);
    Do(L);
    Print(L);
    return 0;
}
