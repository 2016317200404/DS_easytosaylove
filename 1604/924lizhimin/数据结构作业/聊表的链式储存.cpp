/*
    title: 线性表的链式储存
    description:
    author:averyboy
    time:2017/3/17
    version:1.0,0
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<cctype>
#include<ctime>
#define INF 0x3f3f3f3f3
#define PI acos(-1.0)
using namespace std;
typedef struct Node
{
    int value=0;
    Node *next=NULL;
} *listnode;
int length(listnode p)
{
    int cnt=0;
    listnode s=p;
    while(s)
    {
        s=s->next;
        cnt++;
    }
    return cnt;
}
listnode findnum(listnode s,int n)
{
    listnode p=s;
    int cnt=0;
    while(p)
    {
        cnt++;
        if(cnt==n)
            return p;
        p=p->next;
    }
    return NULL;
}
listnode findvalue(listnode s,int n)
{
    listnode p=s->next;
    while(p->value!=n&&p!=NULL)
    {
        p=p->next;
    }
    return p;
}
listnode insnode(listnode s,int n,int v)
{
    listnode p,r;
    if(n==1)
    {
      p=new Node();
      p->next=s;
      p->value=v;
      return p;
    }
    r=findnum(s,n-1);
    if(r==NULL)
    {
        cout<<"input error\n";
        return NULL;
    }
    else
    {
        p=new Node();
        p->next=r->next;
        p->value=v;
        r->next=p;
        return s;
    }
}
void print(listnode s)
{
    listnode p=s;
    while(p!=NULL)
    {
        cout<<p->value<<' ';
        p=p->next;
    }
    cout<<endl;
    return ;
}
int main()
{
    Node p;
    insnode(&p,2,1);
    insnode(&p,2,3);
    insnode(&p,3,4);
    insnode(&p,4,5);
    print(&p);
    cout<<length(&p);
    return 0;
}

