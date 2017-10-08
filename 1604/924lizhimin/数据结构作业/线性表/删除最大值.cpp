#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
struct List
{
    List *Next;
    int data;
    List(int _data=0)
    {
        data=_data;
        Next=NULL;
    }
}*head;
void insert(int data)
{
    List *p=head;
    while(p->Next)
    {
        p=p->Next;
    }
    p->Next=new List(data);
    return ;
}
void output(List *head)
{
    List *p=head;
    while(p->Next)
        cout<<p->Next->data<<" ",p=p->Next;
    cout<<endl;
    return ;
}
void solve(List *head)
{
    int cnt=0;
    List *p=head;
    int maxx=-INF;
    int pos=0;
    while(p->Next)
    {
        pos=p->Next->data>maxx?cnt++:pos;
        p=p->Next;
    }    cnt=0;
    p=head;
    while(cnt<pos)
    {
        p=p->Next;
        cnt++;
    }
    List *q=p->Next->Next;
    p->Next=q;
    return ;

}
int main()
{
    srand(time(NULL));
    head=new List(0);
    for(int i=0;i<10;i++)
        insert(2*i);
    output(head);
    solve(head);
    output((head));
    return 0;
}
