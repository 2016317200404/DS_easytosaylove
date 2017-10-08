#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *back,*next;
}Node,*CLinkList;


int main(){
    Node *p,*s;
    int i;

    p=(CLinkList)malloc(sizeof(Node));
    p->data=0;p->next=p;p->back=p;

    for(i=9;i>=1;i--){
        s=(CLinkList)malloc(sizeof(Node));
        s->data=i;s->next=p->next;p->next=s;s->back=p;s->next->back=s;
    }

    printf("before deleting:\n");
    s=p;
    do{
        printf("%d ",s->data);
        s=s->next;
    }while(s!=p);
    s=p->next;//借用s删除s前驱p


    printf("\nafter deleting:\n");
    s->back=s->back->back;free(s->back->next);s->back->next=s;
    p=s;
    do{
        printf("%d ",s->data);
        s=s->next;
    }while(s!=p);
}
