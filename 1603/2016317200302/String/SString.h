//
// Created by asus on 2017/10/10.
//

#ifndef DATASTRUCTURE_SSTRING_H
#define DATASTRUCTURE_SSTRING_H

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char ch[MAX_SIZE];
    int len;
}SString;

//initialize the SString

void init(SString *s){
    s->len = 0;
}

//copy the string to the SString

void setSString(SString *s , char *t){
    strcpy(s->ch , t);
    s->len = strlen(t);
}

// add a char to the SString

void add(SString *s , char ch){
    s->ch[s->len] = ch;
    s->len ++;
}

//insert

int insert(SString *s , int pos , SString t){
    if(pos < 0 || pos > s->len){
        printf("the position is invalid\n");
        return 0;
    }
        int tail = s->len - 1;
        int ins = 0;
        while (tail >= pos && tail + t.len < MAX_SIZE){
            s->ch[tail + t.len] = s->ch[tail];
            tail --;
        }
        while (ins < t.len && ins + pos < MAX_SIZE){
            s->ch[pos + ins] = t.ch[ins];
            ins ++;
        }
    if(s->len + t.len >= MAX_SIZE)s->len = MAX_SIZE;
    else s->len = s->len + t.len;
    return 1;
}

//delete

int delete(SString * s , int pos , int len){
    if(pos< 1 || len + pos - 1 > s->len ){
        printf("invalid pos or len\n");
        return 0;
    }

    int start = pos + len - 1;
    while (start < s->len){
        s->ch[pos - 1] = s->ch[start];
        start ++;
        pos ++;
    }
    s->len = s->len - len;
    return 1;
}

//compare

int compare(SString s1 , SString s2){
    int i = 0;
    while (i < s1.len && i < s2.len){
        if(s1.ch[i] != s2.ch[i])return s1.ch[i] - s2.ch[i];
        i ++;
    }
    return s1.len - s2.len;
}

//print SString

void printSString(SString s){
    int i;
    for(i = 0 ; i < s.len ; i ++)printf("%c" , s.ch[i]);
    printf("\n");
}


#endif //DATASTRUCTURE_SSTRING_H
