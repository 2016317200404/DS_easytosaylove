/*
 * n queens problem
 * there are n queens
 * and a n X n chessboard
 * */
#include <stdio.h>

int tot,C[100],n;    //C[i] is the position of the queen in i rows
void search(int cur)

{
    if(cur==n)
    {
        tot++;
        int i;
        int j;
        printf("number %d\n\n", tot);
        for( i = 0 ; i < n ; i ++){
            for( j = 0 ; j < n; j ++ ){
                if( j + 1== C[i] + 1)printf("0 ");
                else printf("1 ");
            }
            printf("\n");
        }
        printf("\n\n");
    }
    else for(int i=0;i<n;i++)//外循环，假定一个本列皇后的位置
        {
            int ok=1;
            C[cur]=i;
            for(int j=0;j<cur;j++)//内循环，检查是否与j列的矛盾，若不矛盾则向下一列走，矛盾则改变本列皇后位置
                if(C[cur]==C[j]||cur-C[cur]==j-C[j]||cur+C[cur]==j+C[j])
                {
                    ok=0;break;
                }
            if(ok)search(cur+1);
        }//如果全都矛盾，这条路就不会继续往下走了，废弃掉，不会影响tot的值
}
int main()
{
    tot=0;
    scanf("%d",&n);
    search(0);
    printf("there are %d keys for %d queens problem\n", tot , n);
    return 0;
}
