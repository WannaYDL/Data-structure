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
//��ʼ��
int InitQueue(SqQueue &Q)
{
    Q.base=new QElemType[MAXQSIZE];
    if(!Q.base) return 0;
    Q.front=Q.rear=0;
    return 1;
}
//����г���
int QueueLenth(SqQueue Q)
{
    return (Q.rear-Q.front + MAXQSIZE)%MAXQSIZE;
}
//�����
int EnQueue(SqQueue &Q,QElemType e)
{
    if((Q.rear+1)%MAXQSIZE == Q.front){
        cout<<"����������"<<endl;
        return 0;
    }
    Q.base[Q.rear]=e;
    Q.rear=(Q.rear+1)%MAXQSIZE;
    cout<<"��ӳɹ���"<<endl;
    return 1;
}
//����
int DeQueue(SqQueue &Q,QElemType &e)
{
    if(Q.front==Q.rear){
        cout<<"�����ѿգ�"<<endl;
    }
    e=Q.base[Q.front];
    Q.front = (Q.front+1)%MAXQSIZE;//frontָ������ƶ�һλ
    //���ӳɹ�
    return 1;
}

QElemType GetHead(SqQueue Q)
{
    if(Q.front==Q.rear){
        cout<<"�����Կգ�"<<endl;
        return 0;
    }
    return Q.base[Q.front];

}

int main()
{
    SqQueue Q;
    int choose =-1;
    cout<<"��ѡ�������\n";
    cout<<"�½����У�1\n";
    cout<<"����У� 2\n";
    cout<<"�����У�3\n";
    cout<<"�������Ԫ�أ�4\n";
    cout<<"�˳���0\n";
    while(1){
        cout<<"��ѡ��";
        cin>>choose;
        if(choose==0) break;
        switch(choose){
            case 1:{
            if(InitQueue(Q)){
                cout<<"�½��ɹ���"<<endl;
            }
            else cout<<"�½�ʧ�ܣ�"<<endl;
            }break;
            case 2:{
                int a;
                cout<<"������Ҫ����е�Ԫ�أ�"<<endl;
                cin>>a;
                EnQueue(Q,a);
                cout<<"����Ԫ��Ϊ��";
                cout<<GetHead(Q)<<endl;
            }break;
            case 3:{
                QElemType e;
                DeQueue(Q,e);
                cout<<"�����е�Ԫ��Ϊ��";
                cout<<e<<endl;
                cout<<"��ǰ����Ԫ��Ϊ��";
                cout<<GetHead(Q)<<endl;
            }break;
            case 4:{
                cout<<"����Ԫ��Ϊ��";
                cout<<GetHead(Q)<<endl;
            }break;
        }
    }

    return 0;
}
