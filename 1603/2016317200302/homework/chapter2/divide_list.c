#include<stdio.h>

#include"../List/LinkList.h"


void divideList(LinkList l){
	Node *p , *s;
	p = l;

	while(p->next != NULL){
		p = p->next;

		if( p->next == NULL)break;

		else{

		s = p->next;

	    p->next = p->next->next;//must put here , this two lines cannot change there positions

	    s->next = l->next;

	    l->next = s;
		}
	}
}


int main()
{
	LinkList l;

	InitList(&l);

	int i;

	for( i = 0 ; i < 10 ; i ++)
	{
		CreateFromTail(l , i + 1);

	}
	PrintAll(l);
	divideList(l);
	PrintAll(l);
}
