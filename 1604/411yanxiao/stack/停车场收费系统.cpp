#include<iostream>
#include<cstdio>
#include<stack>
#include<algorithm>
#define fare 100

using namespace std;

struct c
{
    int intime;
    int outtime;
    int lastedtime;
};

c  ca  [100];

stack<int>car;
stack<int>turn;

void in(int carnum,int time)
{
    car.push(carnum);
    ca[carnum].intime = time;
}

void out(int carnum,int time)
{
    while(car.top() != carnum)
    {
        turn.push(car.top());
        car.pop();
    }
    ca[carnum].outtime = time;
    ca[carnum].lastedtime = ca[carnum].outtime - ca[carnum].intime;
    car.pop();
    while(!turn.empty())
    {
        car.push(turn.top());
        turn.pop();
    }
}

int main()
{
    char index[20];
    int num;
    int time;
    while(1)
    {
        scanf("%s %d %d",index,&num,&time);
        if(index[0] == 'i')
            in(num,time);
        if(index[0] == 'o')
        {
            out(num,time);
            printf("费用:%d\n",ca[num].lastedtime*fare);
        }
    }
    return 0;
}
