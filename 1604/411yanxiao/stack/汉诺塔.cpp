#include<iostream>
#include<cstdio>

void move(char a,int b,char c)
{

    printf("%d号盘:%c->%c\n",b,a,c);

}

void Hanoi(int n,char x,char y,char z)
{

    if(n==1) 
      move(x,1,z);

    else
    {

        Hanoi(n-1,x,z,y);

        move(x,n,z);

        Hanoi(n-1,y,x,z);

    }

}

int main()
{

    Hanoi(3,'A','B','C');

    return 0;

}
