
/*the maze problem
 * 2 stands for the start position
 * 3 stands for the end position
 * 0 stands for the road
 * 1 stands for the wall
 * 6 stands for the road you have walked
 * */

/*there are some examples for you
7 6
0 0 1 0 0 3
0 1 0 0 1 1
0 0 0 1 0 0
1 1 0 1 0 1
1 0 0 1 0 1
1 0 0 0 0 0
0 1 0 0 1 2*/

/*
16 12
1 1 1 1 1 1 2 0 0 1 1 1
0 0 0 0 0 0 0 1 0 0 0 0
0 1 0 1 1 0 1 0 0 1 0 1
0 1 0 1 0 0 1 0 1 0 0 0
0 0 1 0 0 1 0 0 1 1 1 0
1 0 1 0 1 0 0 0 0 0 0 1
0 0 1 0 0 0 1 1 1 0 1 1
1 0 1 1 1 0 1 0 0 1 0 0
0 1 0 1 0 0 0 1 0 0 0 1
0 0 0 0 0 1 0 1 0 1 0 1
0 1 1 0 1 0 0 1 1 0 0 0
0 0 1 0 0 1 0 0 0 0 1 0
0 1 0 0 1 0 1 0 0 0 0 0
1 0 0 1 0 0 1 0 1 0 1 0
1 1 0 0 0 0 1 0 1 1 1 1
0 0 0 1 1 0 1 0 0 3 0 0 */

#include<stdio.h>
#define M 100
#define N 100
#define START 2
#define END 3


/*
 * a will store the maze
 * t will store the shortest way to exit the maze
 * tot is the total steps to exit the maze this time
 * min is the min steps to exit the maze
 * it is a x X y maze
 * flag will tell us whether you can exit the maze
 * */
int a[M][N];
int t[M][N];
int tot = 0 , min = 10000 , x , y , flag;
void search(int m , int n){
    int i , j;
    if((a[m][n] == 0 || a[m][n] == START )&& m >= 0 && n >= 0 && m < x && n <y){
        tot ++;
        a[m][n] = 6;
//        for( i = 0 ; i < x ; i ++){
//            for( j = 0 ; j < y ; j ++){
//                printf("%d ",a[i][j]);
//            }
//            printf("\n");
//        }
//        printf("\n\n");
        search( m , n + 1);

        search( m , n - 1 );

        search( m - 1 , n);

        search( m + 1 , n);
        if(a[m][n] != END)    //@csk     notice that END cannot be changed to another number
        a[m][n] = 0;
        tot --;
    }
    else if (a[m][n] == END){
        tot++;
        if(min > tot){
            min = tot;
            for( i = 0 ; i < x ; i ++){
                for( j = 0 ; j < y ; j ++){
                    t[i][j] = a[i][j];
                }
            }
        }
//        printf("exit\n%d steps\n",tot);
//        for( i = 0 ; i < x ; i ++){
//            for( j = 0 ; j < y ; j ++){
//                printf("%d ",a[i][j]);
//            }
//            printf("\n");
//        }
        flag = 1;
    if(a[m][n] != END )
        a[m][n] = 0;
        tot --;
    }

}

int main(){
    flag = 0;
    printf("please enter the size of the maze\n");
    scanf("%d%d", &x , &y);
    int i , j;
    int sx = 0 , sy = 0;
    printf("please enter the maze\n"
                   "notice that\n"
                   "2 stands for the start position\n"
                   "3 stands for the end position\n"
                   "0 stands for the road\n"
                   "1 stands for the wall\n");
    for( i = 0 ; i < x ; i ++){
        for( j = 0 ; j < y ; j ++){
            scanf("%d" , &a[i][j]);
            if( a[i][j] == START ){
                sx = i;
                sy = j;
            }
        }
    }
    search( sx , sy );
    if(flag){
        printf("exit\n%d steps\n",min);
        for( i = 0 ; i < x ; i ++){
            for( j = 0 ; j < y ; j ++){
                printf("%d ",t[i][j]);
            }
            printf("\n");
        }
    } else printf("cannot exit\n");
    return 0;
}

/*
 * 编程时的一致性性与特殊性
 * END 和 START为特殊位置，
 * 但是它们也有一般性
 * 一般性
 * 到达时步数加一
 * 特殊性
 * 离开后不能变成0 或 6*/

/*调试技巧
 * 单步调试应该是最差的调试方法
 * 静态调试时可以发现简单的逻辑错误
 * 打印中间过程量则可以比单步调试更好地看清过程
 * 单步调试的缺点是无法看到数组中的数据
 * 只展示了当前情况，我们会忘记上一步是怎么样的*/