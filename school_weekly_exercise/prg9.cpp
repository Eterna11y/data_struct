#include <iostream>
using namespace std;
typedef struct T_Node
{
    int d;               //数据域
    struct T_Node *next; //指针域
} Node, *List;
void createlink(List *pf)
{
    int i;
    Node *p;

    *pf = (Node *)malloc(sizeof(Node));
    p = *pf;
    for (i = 1; i <= 99; i++)
    {
        p->d = i;
        p->next = (Node *)malloc(sizeof(Node));
        p = p->next;
    }
    p->d = 100;
    p->next = NULL;
}
// 求出所有结点中数值的平均数
// nodenum为结点数的输出参数，	返回平均数，如果为空链表，则返回0。
double getaverage(List f, int *nodenum)
{
    double sum;
    *nodenum = 0;
    List temp = f;
    if (f == nullptr)
    {
        *nodenum = 0;
        return 0.0;
    }
    else
    {
        for (int i = 0; i < 100; i++)
        {
            sum += temp->d;
            temp = temp->next;
            (*nodenum)++;
        }
        sum /= 100;
        return sum;
    }
}
int main(int argc, char *argv[])
{
    int n;
    List f;
    double a;
    createlink(&f);
    a = getaverage(f, &n);
    printf("%d  %lf\n", n, a);
    system("pause");
    return 0;
}
//执行的结果为100  50.500000