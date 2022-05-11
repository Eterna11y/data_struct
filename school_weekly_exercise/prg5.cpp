/*���һ������
	void merge(List La, List Lb)
�书���ǽ�Lb�ϲ���La�У�����La��Lb��Ԫ�ؾ�Ϊ�ϸ�����������У��Һϲ����La��Ԫ��ҲΪ�ǵݼ��������С�
����List�����½ṹ�壺*/
#include<iostream>
#include<malloc.h> 
using namespace std;

typedef struct T_Node{
	int d;
	struct T_Node *next;
} Node, *List;
void merge(List La, List Lb) {
		Node* p1 = La->next;
	Node* p2  =Lb->next;
	Node* pre = La;
	while(p1 && p2) {
		if(p1->d>p2->d) {
			pre->next = p2;
			Node* temp = p2;
			p2 = p2->next;
			temp->next = p1;
			pre = pre->next;
		}else if(p1->d<p2->d){
			p1  =p1->next;
			pre = pre->next;
		}else{
			p1 = p1->next;
			pre = pre->next;
			p2 = p2->next;
		}
	}
	if(p2) {
		pre->next = p2;
	}
}
//��ִ�����µ�main������
int main()
{
	List La, Lb;
	Node *p, *q;
	int i;

	La = (List)malloc(sizeof(Node));
	p = La;
	Lb = (List)malloc(sizeof(Node));
	q = Lb;

	for(i= 1; i<=10;i++)
	{
		p->next = (Node *)malloc(sizeof(Node));
		p->next->d = 2 *i;
		p->next->next = NULL;
		p = p->next;

		q->next = (Node *)malloc(sizeof(Node));
		q->next->d = 3*i -2;
		q->next->next = NULL;
		q = q->next;
	}
	merge(La,Lb);
	p = La->next;
	//printf("\n\n\n");
	while(p!=NULL)
	{
		printf(" %d   ", p->d);
		p = p->next;
	}
	printf("\n");
}
/*ִ�еĽ��Ϊ
1    2    4    6    7    8    10    12    13    14    16    18    19    20    22    25    28
*/
