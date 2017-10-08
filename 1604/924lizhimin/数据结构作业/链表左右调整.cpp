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
    delete[] ls.elem;
    return ;
}
void update(List &a)
{
    int i=0,j=a.sz-1;
    while(i+1<j)
    {
        while(a.elem[i]&1)
            i++;
        while(a.elem[j]%2==0)
            j--;
        swap(a.elem[i],a.elem[j]);
    }
    return ;
}
int main()
{
    List a(10);
    for(int i=0;i<10;i++)
    {
        a.elem[i]=i;
    }
    update(a);
    for(int i=0;i<a.sz;i++)
        cout<<a.elem[i]<<" ";
    cout<<endl;
    List_clear(a);
    return 0;
}
