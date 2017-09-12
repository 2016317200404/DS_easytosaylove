#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
        int data;
        int num;
        struct Node*next;
}Node,*LinkList;

InitCLinkList(LinkList *CL){
    *CL=(LinkList)malloc(sizeof(Node));
    (*CL)->next=*CL;
}
void CreateCLinkList(LinkList CL,int n){
    Node *rear,*s;
    int e,i;
    rear=CL;
    for(i=0;i<n-1;i++){
        s=(Node*)malloc(sizeof(Node));
        scanf("%d",&e);
        s->data=e;
        s->num=i+2;
        rear->next=s;
        rear=s;
    }
    rear->next=CL;
}

int main(){
    int m,n,e;
    int i,j;
    int result[20];
    Node *L,*main,*subsequence;
         /*use main to point the current node and use subsequence to delete this node when jobs are done */

/*init*/
    printf("Please enter the first key 'm',peopler numbers 'n' and all datas in order.\n");
    scanf("%d%d%d",&m,&n,&e);
    InitCLinkList(&L);
    L->data=e;
    L->num=1;
    CreateCLinkList(L,n);
    main=L;
    subsequence=L;

/*core*/
    for(i=0;i<n;i++){
        j=m;
        while(j-2){
            main=main->next;
            subsequence=subsequence->next;
            j--;
        }
        main=main->next;
        result[i]=main->num;
        m=main->data;
        main=main->next;
        subsequence->next=main; /*delete*/
        subsequence=main;
    }

/*print the result*/
    printf("The result is:\n");
    for(i=0;i<n;i++){
        printf("%d ",result[i]);
    }
    return 0;
}
