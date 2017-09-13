#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<cctype>
#include<ctime>
#define INF 0x3f3f3f3f
#define PI acos(-1.0)
using namespace std;
struct FootballPlayer
{
  char name[20];
  int height;
  int age;
  char club[20];
  FootballPlayer *next;
};
void CreateFromHead(FootballPlayer *&f)
{
    FootballPlayer *s=new FootballPlayer();
    cin>>s->name>>s->height>>s->age>>s->club;
    s->next=f;
    f=s;
    return ;
}
void CreateFromTail(FootballPlayer *&f)
{
    FootballPlayer *s=new FootballPlayer();
    FootballPlayer *r=new FootballPlayer();
    cin>>s->name>>s->height>>s->age>>s->club;
    s->next=NULL;
    if(f==NULL)
    {
        f=s;
        return ;
    }
    r=f;
    while(r->next)
    {
        r=r->next;
    }
    r->next=s;
    return ;
}
void Show(FootballPlayer *f)
{
    while(f)
    {
        cout<<f->name<<' '<<f->height<<' '<<f->age<<' '<<f->club<<endl;
        f=f->next;
    }
    return ;
}
int main()
{
 int n,i;
 FootballPlayer *head;
 head=NULL;
 n=6;
 for(i=0;i<n;i++)
    CreateFromHead(head);
 Show(head);
 cout<<endl;
 head=NULL;
 for(i=0;i<n;i++)
    CreateFromTail(head);
Show(head);
 return 0;
}
