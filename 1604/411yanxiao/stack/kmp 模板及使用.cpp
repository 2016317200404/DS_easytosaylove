#include<iostream>
#include<cstdio>
#include<cstring>

//f数组 == next数组
int f[2005];

//获取next数组
void getfill(char s[])
{
    memset(f, 0, sizeof(f));
    int len = strlen(s);
    for(int i = 1;i < len;i++)
    {
        int j = f[i];
        while(j&&s[i] != s[j])
            j = f[j];
        f[i+1] = (s[i] == s[j])?j+1:0;
    }
}

//判断字符串 a 中是否包含字符串 s
//如果包含 返回1 否则 返回0
int fin(char a[], char s[])
{
    getfill(s);
    int j = 0;
    int lena = strlen(a);
    int lens = strlen(s);
    for(int i = 0;i < lena;i++)
    {
        while(j&&a[i]!=s[j])
            j = f[j];
        if(a[i]==s[j])
            j++;
        if(j == lens)
            return 1;
    }
    return 0;
}
