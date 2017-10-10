#include <stdio.h>
#include <stdlib.h>
#include "../../String/SString.h"
#define N 100


//the tools to help you watch the process of KMP
void KMPprint(SString s ,SString t , int si , int ti){
    printSString(s);
    int i;
    for( i = 0 ; i < si - ti ; i ++ )printf(" ");
    printSString(t);
}

int* getNext(SString s ){
    //the next[index] we want to figure out
    int *next = (int*) malloc(N * sizeof(int));
    int j;
    //initialize next[]
    for(j = 0 ; j < s.len ; j ++)next[j] = 0;
    int index = 1;
    next[0] = -1;
    while (index < s.len){
        //i stands for the length of the substring
        int i = 1;
        while ( i < index){
            //front point at the left substring
            //rear point at the right substring
            int front = 0;
            int rear = index - i;
            while (s.ch[rear] == s.ch[front] && rear <index){
                front ++;rear ++;
            }
            if(rear == index){
                next[index] = i  > next[index] ? i : next[index];
            }
            i ++;
        }
        index ++;
    }
    return next;
}


int KMP(SString s , SString t , int next[]){
    int si = 0 , ti = 0;
    while (si + t.len - ti <= s.len){
        KMPprint(s , t , si , ti);
        while (s.ch[si] == t.ch[ti] && ti < t.len){
            si ++;ti ++;
        }
        if(ti == t.len)return 1;
        else{
            if(next[ti] == -1)si ++;
            else ti = next[ti];
        }
    }
    if(ti == t.len)return 1;
    return 0;
}


int main(){
    SString s , t;
    init(&s);
    init(&t);
    char temp[N];
    printf("please enter the primary string\n");
    gets(temp);
    printf("%s\n" , temp);
    setSString(&s , temp);
    printf("please enter the pattern string\n");
    gets(temp);
    printf("%s\n" , temp);
    setSString(&t , temp);
    int *p = getNext(t);
    int i;
    //print the next[]
    for(i = 0 ; i < t.len ; i ++){
        printf("%d " , p[i]);
    }
    printf("\n");
    printf("\n%d\n" , KMP(s , t , p));
    return 0;
}

/*
 ababcabcacbab
 abcac
 */