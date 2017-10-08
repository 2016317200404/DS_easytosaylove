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
}*head;
void insert(int _a,int _b)
{
    List *p=head;
    while(p->Next)
    {
        p=p->Next;
    }
    p->Next=new List(_a,_b);
}
void output()
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
    while(~scanf("%d%d",&a,&b))
    {
        head->a++;
        insert(a,b);
        output();
    }
    return 0;
}
