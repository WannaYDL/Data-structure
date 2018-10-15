#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXQSIZE 100
typedef int QElemType;
using namespace std;

typedef struct
{
    QElemType *base;
    int front;
    int rear;
}SqQueue;
//初始化
int InitQueue(SqQueue &Q)
{
    Q.base=new QElemType[MAXQSIZE];
    if(!Q.base) return 0;
    Q.front=Q.rear=0;
    return 1;
}
//求队列长度
int QueueLenth(SqQueue Q)
{
    return (Q.rear-Q.front + MAXQSIZE)%MAXQSIZE;
}
//入队列
int EnQueue(SqQueue &Q,QElemType e)
{
    if((Q.rear+1)%MAXQSIZE == Q.front){
        cout<<"队列已满！"<<endl;
        return 0;
    }
    Q.base[Q.rear]=e;
    Q.rear=(Q.rear+1)%MAXQSIZE;
    cout<<"入队成功！"<<endl;
    return 1;
}
//出队
int DeQueue(SqQueue &Q,QElemType &e)
{
    if(Q.front==Q.rear){
        cout<<"队列已空！"<<endl;
    }
    e=Q.base[Q.front];
    Q.front = (Q.front+1)%MAXQSIZE;//front指针向后移动一位
    //出队成功
    return 1;
}

QElemType GetHead(SqQueue Q)
{
    if(Q.front==Q.rear){
        cout<<"队列以空！"<<endl;
        return 0;
    }
    return Q.base[Q.front];

}

int main()
{
    SqQueue Q;
    int choose =-1;
    cout<<"请选择操作：\n";
    cout<<"新建队列：1\n";
    cout<<"入队列： 2\n";
    cout<<"出队列：3\n";
    cout<<"输出队首元素：4\n";
    cout<<"退出：0\n";
    while(1){
        cout<<"请选择：";
        cin>>choose;
        if(choose==0) break;
        switch(choose){
            case 1:{
            if(InitQueue(Q)){
                cout<<"新建成功！"<<endl;
            }
            else cout<<"新建失败！"<<endl;
            }break;
            case 2:{
                int a;
                cout<<"请输入要如队列的元素："<<endl;
                cin>>a;
                EnQueue(Q,a);
                cout<<"队首元素为：";
                cout<<GetHead(Q)<<endl;
            }break;
            case 3:{
                QElemType e;
                DeQueue(Q,e);
                cout<<"出队列的元素为；";
                cout<<e<<endl;
                cout<<"当前队首元素为：";
                cout<<GetHead(Q)<<endl;
            }break;
            case 4:{
                cout<<"队首元素为：";
                cout<<GetHead(Q)<<endl;
            }break;
        }
    }

    return 0;
}
