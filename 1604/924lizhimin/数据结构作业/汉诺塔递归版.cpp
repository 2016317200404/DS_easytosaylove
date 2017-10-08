#include<bits/stdc++.h>
using namespace std;
int hanoi(int n,char x,char y,char z)//盘从上倒下一次编号1-n，从x搬到z上，y为辅助塔
{
    static int ans=0;
    if(n==1)
    {
        cout<<x<<"->"<<z<<endl;
        ans++;
        return ans;
    }
    hanoi(n-1,x,z,y);
    cout<<x<<"->"<<z<<endl;
    ans++;
    hanoi(n-1,y,x,z);

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
