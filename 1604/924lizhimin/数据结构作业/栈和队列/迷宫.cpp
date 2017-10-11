#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int mp[maxn][maxn];//0能走，1不能走;
int vis[maxn][maxn];//标记数组，0代表未走过
int n,m;
int sx,sy,tx,ty;
bool check(int x,int y)
{
    return x>=0&&x<n&&y>=0&&y<m&&!vis[x][y]&&!mp[x][y];
}
bool dfs(int x,int y)
{
    cout<<"x y: "<<x<<" "<<y<<endl;
    vis[x][y]=1;
    if(x==tx&&y==ty)
    {
        return true;
    }
    else
    {
        if(check(x-1,y))
            return dfs(x-1,y);
        if(check(x+1,y))
            return dfs(x+1,y);
        if(check(x,y+1))
            return dfs(x,y+1);
        if(check(x,y-1))
            return dfs(x,y-1);
    }
    return false;
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                scanf("%d",&mp[i][j]);
            }
        scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
        if(dfs(sx,sy))
            cout<<"能走出迷宫"<<endl;
        else
            cout<<"不能走出迷宫"<<endl;
    }
    return 0;
}
