#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
struct Queue
{
    int head,sz;
    Queue()
    {
        head=sz=0;
    }
    int elem[maxn];
    int size()
    {
        return sz-head;
    }
    void pop()
    {
        head++;
    }
    int front()
    {
        return elem[head];
    }
    bool empty()
    {
        return head==sz;
    }
    void push(int data)
    {
        elem[sz++]=data;
        return ;
    }
};
int main()
{
    Queue qe;;
    srand(time(NULL));
    for(int i=0;i<10;i++)
    {
        int num=rand()%100+1;
        cout<<num<<" ";
        qe.push(num);
    }
    cout<<endl;
    while(!qe.empty())
    {
        cout<<qe.front()<<endl;;
        qe.pop();
    }
    return 0;
}
