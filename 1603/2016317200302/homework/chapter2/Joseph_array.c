#include<stdio.h>
#define N 100
int a[2][N];
void solve(int start , int code , int size)
{
    int i;
    int newStart , newCode;
    if( size <1)return;
    else
    {

        newStart = (start - 1 + code)%size;
        if(newStart == 0)newStart = size;
        newCode = a[0][newStart - 1];
        printf("%d " , a[1][newStart-1]);
        for(i = newStart - 1 ; i < size -1 ; i ++)
        {
            a[0][i] = a[0][i + 1];
            a[1][i] =a [1][i+1];
        }
        solve(newStart , newCode , --size);
    }
}
int main()
{   int start , code , size , i;
    printf("please enter the start , code , size !\n");
    scanf("%d%d%d",&start , &code , &size);
    printf("please enter the code of each person !\n");
    for(i = 0 ; i < size ; i ++){
        a[1][i] = i + 1;
        scanf("%d", &a[0][i]);
    }
    solve(start , code , size);
    return 0;
}
