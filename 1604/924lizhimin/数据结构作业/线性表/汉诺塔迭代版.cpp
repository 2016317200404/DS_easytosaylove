#include<bits/stdc++.h>
using namespace std;
struct tower
{
    int n;
    char a,b,c;
    tower(int _n,char _a,char _b,char _c)//表示状态
    {
        n=_n;
        a=_a;
        b=_b;
        c=_c;
    }
};
stack<tower>st;//使用栈模拟递归过程
int hanoi(int n,char a,char b,char c)
{
    static int ans=0;
    st.push(tower(n,a,b,c));
    while(!st.empty())
    {
        tower p=st.top();
        st.pop();
        if(p.n==1)
        {
            ans++;
            cout<<p.a<<"->"<<p.c<<endl;
        }
        else
        {
            st.push(tower(p.n-1,p.b,p.a,p.c));
//            cout<<p.a<<"->"<<p.c<<endl;
//            ans++;
            st.push(tower(1,p.a,p.b,p.c));
            st.push(tower(p.n-1,p.a,p.c,p.b));
        }
    }
    return ans;
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        cout<<hanoi(n,'a','b','c')<<endl;
    }
    return  0;
}
