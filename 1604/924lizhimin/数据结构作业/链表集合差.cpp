#include<bits/stdc++.h>
using namespace std;
struct List
{
    int sz;
    int *elem;
    List(int _sz)
    {
        sz=_sz;
        elem=new int[sz];
    }
};
void List_insert(List ls,int x,int p)
{
    for(int i=ls.sz;i>x;i--)
    {
        ls.elem[i]=ls.elem[i-1];
    }
    ls.sz++;
    ls.elem[x]=p;
    return ;
}
void List_delete(List ls,int x)
{
    for(int i=x;i<ls.sz-1;i++)
    {
        ls.elem[i]=ls.elem[i+1];
    }
    ls.sz--;
    return ;
}
int List_find(List ls,int x)
{
    return ls.elem[x];
}
void List_clear(List& ls)
{
    delete ls.elem;
    return ;
}
List sub(List a,List b)
{
    int sza=a.sz;
    int szb=b.sz;
    int vis[szb];
    memset(vis,0,sizeof(vis));
    int c[sza];
    int num=0;
    int i,j;
    for(i=0;i<sza;i++)
    {
        for(j=0;j<szb;j++)
        {
            if(a.elem[i]==b.elem[j]&&!vis[j])
            {
                vis[j]=1;
                break;
            }
        }
        if(j==szb)
            c[num++]=a.elem[i];
    }
    List ans(num);
    for(int i=0;i<num;i++)
    {
        ans.elem[i]=c[i];
    }
    return ans;
}
int main()
{
    List a(10);
    List b(10);
    for(int i=0;i<10;i++)
    {
        a.elem[i]=i;
        b.elem[i]=i*2;
    }
    for(int i=0;i<a.sz;i++)
        cout<<a.elem[i]<<" ";
    cout<<endl;
    for(int i=0;i<b.sz;i++)
        cout<<b.elem[i]<<" ";
    cout<<endl;
    List c=sub(a,b);
    for(int i=0;i<c.sz;i++)
        cout<<c.elem[i]<<" ";
    cout<<endl;
    return 0;
}
