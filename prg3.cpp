#include<stdio.h>
#include<stdlib.h>
using namespace std;
typedef struct T_Node{
	int d;
	struct T_Node *next;
} Node, *List;
void createlink(List *pla)
{
	int i;
	Node *p;

	*pla = (Node *)malloc(sizeof(Node));     //创建头结点
	p = *pla;

	for(i = 1; i <=10;i++)
	{
		p->next = (Node *)malloc(sizeof(Node));		
		p = p->next;
		p->d = i;
		p->next = NULL;
	}
}
void LinkReverse(List *pla) {
	Node* p = (*pla)->next->next;
	while(p!=NULL) {
		Node *temp = p;
		p = p->next;
		temp->next = (*pla)->next;
		(*pla)->next = temp;
	}
}
int main( )
{
	List la, p;
	int i;

	createlink(&la);
	LinkReverse(&la);

	p = la->next;
	for(i = 1; i <=10;i++)
	{
		printf("%4d",p->d);
		p = p->next;
	}
	printf("\n");
	return 0;
}
