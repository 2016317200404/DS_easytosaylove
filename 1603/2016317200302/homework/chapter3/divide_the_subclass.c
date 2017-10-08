#include <stdio.h>
#include "../../Queue/Queue.h"
#define N 100

/*
the example
 2 8
 9 4
 2 9
 2 1
 2 5
 6 2
 5 9
 5 6
 5 4
 7 5
 7 6
 3 7
 6 3
 0 0
*/

Queue cq;
int newr[N] ={0};
int result[N] = {0};
//flag is the first number of the new loop
//counter will count the time of the loop
int flag = 0 , counter = 0;
//map is the relationship matrix
int map[N][N] = {0};
int a[N] = {0};

void divide(int k){

    if( k == flag ){
        int i;
        for( i = 1 ; i < N ; i ++)newr[i] = 0;
        counter ++;
        flag = 0;
    }
    if( ! newr[k]){
        int i;
        for(i = 1 ; i < N ; i ++){
            newr[i] = newr[i] || map[k][i];
            result[k] = counter;
        }
    } else{
        if(!flag) flag = k;
        enter(&cq , k);
    }
}

int main(){
    int ai , bi;
    while (scanf("%d%d",&ai , &bi) && ai && bi){
        //build the relationship matrix
        map[ai][bi] = 1;
        map[bi][ai] = 1;
        //build set a
        a[ai] = a[bi] = 1;
    }
// print the matrix
//    int i , j;
//    for( i = 1 ; i < 10 ; i ++){
//        for( j = 1 ; j < 10 ; j ++){
//            printf("%d " , map[i][j]);
//        }
//        printf("\n");
//    }
    InitQueue(&cq);
    int i , j;
    for(i = 0 ; i < N ; i ++){
        if(a[i])enter(&cq , i);
    }

    flag = get(cq);
    counter =  0;

    while (!isEmpty(cq)){
        divide(get(cq));
        delete(&cq);
    }
    //print the result
    for( i = 1 ; i <= counter ; i ++){
        printf("A%d " , i);
        for(j = 1 ; j < N ; j ++){
            if(result[j] == i){
                printf("%d " , j);
            }
        }
        printf("\n");
    }
    return 0;
}