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
int main()
{
    List ls(10);
    for(int i=0;i<ls.sz;i++)
        cout<<ls.elem[i]<<" ";
    cout<<endl;
    List_insert(ls,0,2);
    List_insert(ls,3,4);
    for(int i=0;i<ls.sz;i++)
        cout<<ls.elem[i]<<" ";
    cout<<endl;
    List_delete(ls,3);
    for(int i=0;i<ls.sz;i++)
        cout<<ls.elem[i]<<" ";
    cout<<endl;
    cout<<List_find(ls,0)<<endl;
    List_clear(ls);
    return 0;
}

