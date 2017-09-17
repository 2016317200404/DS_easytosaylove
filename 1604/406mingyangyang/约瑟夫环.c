#include<stdio.h>
#include<stdlib.h>
#define MAX 20
typedef struct node
{
    int elem;
    int m;
    struct node *next;
}node;
void createlist(node* head)
{
    node*rear,*p;
    head=malloc(sizeof(node));
    head->next=head;
    int a,b;
    rear=head;
    while(scanf("%d %d",&a,&b)&&(a!=0||b!=0))
    {
        p=malloc(sizeof(node));
        p->elem=a;
        p->m=b;
        rear->next=p;
        rear=p;
    }
}
void Del(node* head,int s,int *e1,int*e2)
{
    node*pre,*r;
    int k=0;
    pre=head;
    while(pre->next!=NULL&&k<s-1)
    {
        pre=pre->next;
        k++;
    }
    r=pre->next;
    pre->next=r->next;
    *e1=r->m;
    *e2=r->elem;
    free(r);
}
int main()
{
    node*head;
    createlist(head);
    int m=20,s=1;
    int*p1,*p2;
    while(s)
    {
        s=(s+m-1)%1;
        Del(head,s,p1,p2);
        m=*p1;
        printf("%d ",*p2);
    }
    return 0;
}









