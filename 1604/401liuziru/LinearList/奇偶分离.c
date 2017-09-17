c#include<stdio.h>

int main(){
    int la[50],i=0,temp;
    int start=0,end;

/*get data*/
    printf("Please enter some numbers for la[] and end by ENTER.\n");
    do{
        scanf("%d",&la[i++]);
    }while(getchar()!='\n');
    end=i-1;

/*change elements*/
    while(start<end){
        while(start<end&&la[start]%2!=0)start++;
        while(start<end&&la[end]%2==0)end--;
        temp=la[start];
        la[start]=la[end];
        la[end]=temp;
    }
    end=i;

/*put data out*/
    for(i=0;i<end;i++) printf("%d ",la[i]);
    return 0;
}
