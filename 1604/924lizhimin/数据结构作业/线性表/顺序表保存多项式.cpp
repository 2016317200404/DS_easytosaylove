#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int num[maxn]; //num数组保存系数，指数与数组下标相对应
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",num+i);
        }
        cout<<"多项式为:"<<endl;
        cout<<num[0];
        for(int i=1;i<n;i++)
        {
            cout<<"+"<<num[i]<<"x^"<<i;
        }
    }
    return 0;
}
