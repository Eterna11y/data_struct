#include<iostream>
using namespace std;
#define MAX 20
typedef struct{
int n;    //顺序表元素个数
int data[MAX+1];   //存放元素的数组，下标从1开始
} SEQTABLE; 
void delitem(SEQTABLE *st, int item)//删除所有item 
{
	int count = 0;
	for(int i=1 ; i <= st->n ; i++) {
		if(st->data[i]==item) {
			count++;
		}else{
			st->data[i-count] = st->data[i];
		}
	}
	st->n -=count;
}

int  main(int argc, char* argv[])
{
	int i;

	SEQTABLE st = {9, {0,5,7,9,8,7,2,6,7,9}};
	delitem(&st, 7);

	for(i = 1; i <= st.n; i++)
	{
		printf("%4d", st.data[i]);
	}
	printf("\n");
	return 0;
}
