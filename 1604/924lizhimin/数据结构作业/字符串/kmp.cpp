#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
char t[maxn],p[maxn];
int Next[maxn];//Next[i]保存str[0-i]的最长公共前后缀长度
void get_Next(char *p)
{
    int k=0;
    int lenp=strlen(p);
    Next[0]=0;
    for(int i=1;i<lenp;i++)
    {
        while(k&&p[i]!=p[k])
        {
            k=Next[k-1];
        }
        if(p[i]==p[k])
            k++;
        Next[i]=k;
    }
    return ;
}
int kmp(char *t,char *p)//找到p在t中第一次出现的位置
{
    int k=0;
    int lenp=strlen(p);
    for(int i=0;t[i];i++)
    {
        while(k&&t[i]!=p[k])
        {
            k=Next[k-1];
        }
        if(t[i]==p[k])
            k++;
        if(k==lenp)
            return i+1-lenp;
    }
    return -1;
}
int main()
{
    while(~scanf("%s%s",p,t))
    {
        get_Next(p);
        for(int i=0;p[i];i++)
            cout<<Next[i]<<" ";
        cout<<endl;
        cout<<kmp(t,p)<<endl;
    }
    return 0;;
}
