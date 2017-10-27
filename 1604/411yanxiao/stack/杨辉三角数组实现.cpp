#include<iostream>
#include<cstdio>
#include<cstring>

int main()
{
    int sta[20][20];
    memset(sta,0,sizeof(sta));
    for(int i = 0;i < 20; i++)
        sta[i][0] = sta[i][i] = 1;
    for(int i = 1;i < 20; i++ )
        for(int k = 1; k < 20; k++)
        sta[i][k] = sta[i-1][k-1] + sta[i-1][k];
    for(int i = 0; i < 20; i++)
    {
        for(int k = 0; k <= i; k++)
            printf("%d ",sta[i][k]);
        printf("\n");
    }
    return 0;
}
