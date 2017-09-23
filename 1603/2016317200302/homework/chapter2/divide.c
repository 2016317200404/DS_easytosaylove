#include<stdio.h>
#include"../List/SqList.h"
int main()
{
    SeqList l;
    InitList(&l);
    int i;
    for( i = 0 ; i < 100 ; i ++)
    {
        InseList(&l , i + 1 , rand()%100);
    }
    PrintAll(l);
    printf("*\n*\n*\n");
   divide(&l);
   PrintAll(l);
    return 0;
}


//divide the list

void divide(SeqList* l)
{
    int i , j;
    int temp;
    for( i = 0 , j = l->last ; i < j ; i ++ , j--)
    {
        while( l->elem[i] % 2 == 0 && i < j)i++;
        while( l->elem[j] % 2 != 0 && i < j)j--;
        temp = l->elem[i];
        l->elem[i] = l->elem[j];
        l->elem[j] = temp;
    }
}
