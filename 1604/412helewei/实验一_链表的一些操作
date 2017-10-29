#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
struct node
{
    int data;
    node *next;
};
node* build(node *l,int n)
{
    node *s;
    while(n--)
    {
        s=new node;
        scanf("%d",&s->data);
        s->next=l->next;
        l->next=s;
    }
    return l;
}
void get(node *l,int a)
{
    node *p=l->next;
    if(a<=0)
    {
        printf("get fail\n");
        return;
    }
    a--;
    while(a--)
    {
        if(p==NULL)
            break;
        p=p->next;
    }
    if(p==NULL)
        printf("get fail\n");
    else
        printf("%d\n",p->data);
}
void del(node *l,int a)
{
    node *p=l->next;
    node *q=l;
    if(a<=0)
    {
        printf("delete fail\n");
        return;
    }
    a--;
    while(a--)
    {
        if(p==NULL)
            break;
        q=p;
        p=p->next;
    }
    if(p==NULL)
        printf("delete fail\n");
    else
    {
        q->next=p->next;
        printf("delete OK\n");
    }
}
void show(node *l)
{
    node *p=l->next;
    if(p!=NULL)
        printf("%d",p->data);
    else
    {
        printf("Link list is empty\n");
        return;
    }
    p=p->next;
    while(p!=NULL)
    {
        printf(" %d",p->data);
        p=p->next;
    }
    printf("\n");
}
void ins(int a,int e,node *l)
{
    node *p=l->next;
    node *q=l;
    node *r=new node;
    if(a<=0)
    {
        printf("insert fail\n");
        return;
    }
    if(a==1)
    {
        q->next=r;
        r->data=e;
        r->next=p;
        printf("insert OK\n");
        return;
    }
    a=a-1;
    while(a--)
    {
        if(p==NULL)
            break;
        q=p;
        p=p->next;
    }
    if(p==NULL)
        printf("insert fail\n");
    else
    {
        q->next=r;
        r->data=e;
        r->next=p;
        printf("insert OK\n");
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    node *q=new node;
    q->next=NULL;
    node *l=build(q,n);
    string s;
    int m;
    scanf("%d",&m);
    int a,b;
    int cnt=1;
    while(m--)
    {
        //cout<<cnt++<<endl;
        cin>>s;
        if(s=="show")
            show(l);
        else if(s=="delete")
        {
            scanf("%d",&a);
            del(l,a);
        }
        else if(s=="get")
        {
            scanf("%d",&a);
            get(l,a);
        }
        else
        {
            scanf("%d%d",&a,&b);
            ins(a,b,l);
        }
    }
    return 0;
}
