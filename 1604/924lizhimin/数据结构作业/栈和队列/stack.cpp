#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
struct Stack
{
    static int sz;
    int elem[maxn];
    int size()
    {
        return sz;
    }
    void pop()
    {
        sz--;
    }
    int top()
    {
        return elem[sz-1];
    }
    bool empty()
    {
        return sz==-1;
    }
    void push(int data)
    {
        elem[sz++]=data;
        return ;
    }
};
int Stack::sz=0;
int main()
{
    Stack st;
    srand(time(NULL));
    for(int i=0;i<10;i++)
    {
        int num=rand()%100+1;
        cout<<num<<" ";
        st.push(num);
    }
    cout<<endl;
    while(!st.empty())
    {
        cout<<st.top()<<endl;;
        st.pop();
    }
    return 0;
}
