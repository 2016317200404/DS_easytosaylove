/*
    一元稀疏多项式以单循环链表按降幂排列，结点有三个域， 系数域coef、指数域exp和指针域next；
    现对链表求一阶导数 ，链表的头指针为ha，头结点的exp域为-1。
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
        int coef,exp;
        struct Node *next;
}Node,*LinkList;

InitCLinkList(LinkList *CL){
    *CL=(LinkList)malloc(sizeof(Node));
    (*CL)->exp=-1;
    (*CL)->next=*CL;
}
void CreateCLinkList(LinkList CL){
    Node *rear,*s;
    int a,b;
    rear=CL;
    while(1){
        s=(Node*)malloc(sizeof(Node));
        scanf("%d%d",&a,&b);
        s->coef=a;s->exp=b;
        rear->next=s;
        rear=s;
        if(b==0) break;
    }
    rear->next=CL;
}

void derivative(LinkList ha){
    LinkList pa,q;
    q=ha;pa=ha->next;
    while(pa->exp!=-1){
        if(pa->exp==0){
            q->next=pa->next;
            free(pa);
            pa=q->next;
        }
        else{
            pa->coef*=pa->exp;
            pa->exp--;
            q=q->next;
            pa=pa->next;
        }
    }
}
int main(){
    int i;
    LinkList ha,pa;
    InitCLinkList(&ha);
    CreateCLinkList(ha);
    derivative(ha);

/*pirnt the result*/
    printf("The result is:\n");
    pa=ha->next;
    printf("F(x)'=%dx^%d",pa->coef,pa->exp);
    while(pa->next->exp!=-1){
            pa=pa->next;
            if(pa->coef>=0) printf("+%dx^%d",pa->coef,pa->exp);
            else printf("%dx^%d",pa->coef,pa->exp);
        }
    return 0;
}
