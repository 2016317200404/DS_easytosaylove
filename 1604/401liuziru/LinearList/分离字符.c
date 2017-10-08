#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
        char data;
        struct Node *next;
}Node,*LinkList;


InitCLinkList(LinkList *CL){
    *CL=(LinkList)malloc(sizeof(Node));
    (*CL)->next=*CL;
}

InitLinkList(LinkList *L){
    *L=(LinkList)malloc(sizeof(Node));
    (*L)->next=NULL;
}
void CreateLinkList(LinkList L){
    Node *rear,*s;
    char e;
    rear=L;
    e=getchar();
    while('$'!=e){
        s=(LinkList)malloc(sizeof(Node));
        s->data=e;
        rear->next=s;rear=rear->next;
        e=getchar();
    }
    rear->next=NULL;
}
void Print(LinkList L){
    LinkList p=L->next;
    while(p!=L&&p!=NULL){
        printf("%c ",p->data);
        p=p->next;
    }
    printf("\n");
}

void divide(LinkList L,LinkList Lnumber,LinkList Lcharacter,LinkList Lothers){
    char e;
    LinkList p=L,rearn=Lnumber,rearc=Lcharacter,rearo=Lothers;
    while(L->next){
        e=L->next->data;
        if(e>=48&&e<=57){
            rearn->next=L->next;
            rearn=L->next;
            L->next=L->next->next;
            rearn->next=NULL;

        }
        else if(e>=65&&e<=90||e>=97&&e<=122){
            rearc->next=L->next;
            rearc=L->next;
            L->next=L->next->next;
            rearc->next=NULL;

        }
        else{
            rearo->next=L->next;
            rearo=L->next;
            L->next=L->next->next;
            rearo->next=NULL;
        }
    }
    rearn->next=Lnumber;
    rearc->next=Lcharacter;
    rearo->next=Lothers;
}

int main(){
    LinkList L;
    LinkList Lnumber,Lcharacter,Lothers;
    InitLinkList(&L);
    printf("What you inputed shouldn't include blankspaces:\n");
    CreateLinkList(L);//原始链表的创建
    InitLinkList(&Lnumber);InitLinkList(&Lcharacter);InitLinkList(&Lothers);//初始新表头
    divide(L,Lnumber,Lcharacter,Lothers);
    Print(Lnumber);Print(Lcharacter);Print(Lothers);
    return 0;
}
