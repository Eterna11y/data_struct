#include <iostream>
using namespace std;
typedef int QueueElementType;
#define Maxsize 50
#define TRUE 1
#define FALSE 0

typedef struct
{
    QueueElementType element[Maxsize];
    int front; //头指针
    int rear;  //尾指针
} SeqQueue;
void InitQueue(SeqQueue *q) //初始化队列
{
    q->front = q->rear = 0;
}
int EnterQueue(SeqQueue *q, QueueElementType x) //入队操作
{
    if ((q->rear + 1) % Maxsize == q->front) //队满
    {
        return FALSE;
    }
    q->element[q->rear] = x;
    q->rear = (q->rear + 1) % Maxsize;
    return TRUE;
}
int DeleteQueue(SeqQueue *q, QueueElementType *x) //出队操作
{
    if (q->front == q->rear) //队空
    {
        return FALSE;
    }
    else
    {
        *x = q->element[q->front];
        q->front = (q->front + 1) % Maxsize;
        return TRUE;
    }
}
int GetHead(SeqQueue *q, QueueElementType *x) //取队头元素
{
    if (q->front == q->rear)
    {
        return FALSE;
    }
    *x = q->element[q->front];
    return TRUE;
}

int IsEmpty(SeqQueue q) //判空
{
    if (q.front == q.rear)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
//杨辉三角
void YHTriangle(int N)
{
    int temp;
    int x;
    SeqQueue Triangle;
    InitQueue(&Triangle); //初始化杨辉三角
    EnterQueue(&Triangle, 1);
    cout << "1" << endl;         //第一行元素入队
    for (int i = 2; i <= N; i++) //产生N行杨辉三角
    {
        EnterQueue(&Triangle, 1); //最左边的元素为1
        GetHead(&Triangle, &x);
        cout << x << " ";
        for (int j = 0; j < i - 2; j++) //从每行的第二项开始生成
        {

            DeleteQueue(&Triangle, &x);
            GetHead(&Triangle, &temp);
            temp = temp + x;
            cout << temp;
            EnterQueue(&Triangle, temp);
            cout << " ";
        }
        EnterQueue(&Triangle, 1); //最右边元素为1
        DeleteQueue(&Triangle, &x);
        GetHead(&Triangle, &x);
        cout << x << " " << endl;
    }
}
int main()
{
    YHTriangle(6);
    return 0;
}