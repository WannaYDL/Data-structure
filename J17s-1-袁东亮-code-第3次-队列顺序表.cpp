#include <iostream>

using namespace std;
const int MAXQUEUE=100;
typedef struct{
    int *base;
    int front;
    int rear;
}SqQueue;
//��ʼ��
int InitQueue(SqQueue &Q)
{

    Q.base= new int[MAXQUEUE];
    if(!Q.base)return 0;
    Q.front=Q.rear=0;
    return 1;
}
//����
int QueueLen(SqQueue Q)
{
    return (Q.rear-Q.front+MAXQUEUE)%MAXQUEUE;
}
//���
int EnQueue(SqQueue &Q,int e)
{
    if(Q.rear-Q.front==MAXQUEUE){
        cout<<"����������"<<endl;
        return 0;
    }
    Q.base[Q.rear]=e;
    Q.rear=(Q.rear+1)%MAXQUEUE;
    return 1;
}
int PopQueue(SqQueue &Q,int &e)
{
    if(Q.front==Q.rear){
        cout<<"�����ǿյģ�"<<endl;
        return 0;
    }
    e=Q.base[Q.front];
    Q.front=(Q.front-1)%MAXQUEUE;
    return 1;
}
int GetHead(SqQueue Q)
{
    if(Q.front!=Q.rear){
        return Q.base[Q.front];
    }
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
                int e;
                PopQueue(Q,e);
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

