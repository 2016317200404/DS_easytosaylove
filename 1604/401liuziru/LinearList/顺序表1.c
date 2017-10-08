#include<stdio.h>

int main(){
    int la[50],lb[50],lc[50];
    int i=0,j=0,flag=1;
    int counta=0,countb=0,countc=0;

/*get data*/
    printf("Please enter some numbers for la[] and end by ENTER.\n");
    do{
        scanf("%d",&la[i++]);
    }while(getchar()!='\n');
    counta=i;
    i=0;

    printf("Please enter some numbers for lb[] and end by ENTER.\n");
    do{
        scanf("%d",&lb[i++]);
    }while(getchar()!='\n');
    countb=i;
    i=0;

/*make subtract*/
    for(i=0;i<counta;i++){
        for(j=0;j<countb;j++){
            if(la[i]==lb[j]) flag=0;
        }
        if(flag){
            lc[countc]=la[i];
            countc++;
        }
        flag=1;
    }

/*put result out*/
    printf("The result of ''la-lb'' is:\n");
    for(i=0;i<countc;i++){
        printf("%d ",lc[i]);
    }

    return 0;
}
