#include<bits/stdc++.h>
using namespace std;
struct List
{
    int a,b;
    List *Next;
    List(int _a,int _b=0)
    {
        Next=NULL;
        a=_a;
        b=_b;
    }
}*head,*der;
void insert(int _a,int _b)
{
    List *p=head;
    while(p->Next)
    {
        p=p->Next;
    }
    p->Next=new List(_a,_b);
}
List* get_der()
{
    List *q=new List(0,0);
    List *ans=q;
    q->a=head->a;
    List *p=head->Next;
    for(int i=0;i<head->a&&p;i++)
    {
        q->Next=new List(0,0);
        if(p->b==0)
        {
            q->Next->a=0;
            q->Next->b=0;
            p=p->Next;
        }
        else
        {
            q->Next->a=(p->a)*(p->b);
            q->Next->b=(p->b)-1;
        }
        p=p->Next;
        q=q->Next;
    }
    return ans;
}
void output(List *head)
{
    List *p=head;
    if(p->Next)
    cout<<"多项式为：";
        cout<<p->Next->a<<"x^"<<p->Next->b;
    p=p->Next;
    while(p->Next)
    {
        cout<<"+"<<p->Next->a<<"x^"<<p->Next->b;
        p=p->Next;
    }
    cout<<endl;
    return ;
}
int main()
{
    int a,b;
    head=new List(0,0);
    der=new List(0,0);
    while(~scanf("%d%d",&a,&b))
    {
        head->a++;
        insert(a,b);
        output(head);
        output(get_der());
    }
    return 0;
}
