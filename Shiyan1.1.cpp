#include <iostream>
#include<fstream>
#include<cstring>
#include<iomanip>
#include <cstdio>
using namespace std;
const int MAXSIZE=100;
#define OVERFLOW -2
struct Elem{
    int data;
};

typedef struct{
    Elem *elem;
    int length;
}SqList;
//��ʼ��
int InitList(SqList &L){
    L.elem = new Elem[MAXSIZE];
    if(!L.elem)
        return (OVERFLOW);
    L.length=0;
    return 1;
}
//����
int ListInsert(SqList &L, int i, Elem e){
//��˳���ĵ�i��λ�ò����µ�Ԫ��e 1<=i<=length+1
    int j;
    if((i<1)||(i>L.length+1)) return 0;
    if(L.length==MAXSIZE) return 0;
    for(j=L.length-1;j>=i-1;j--){
        L.elem[j+1]=L.elem[j];
    }
    L.elem[i-1]=e;
    ++L.length;
    return 1;
}
//ȡֵ
int GetElem(SqList &L,int i,Elem &e){
    if((i<1)||(i>L.length)) return 0;
    e=L.elem[i-1];
    return 1;
}
//ɾ��
int ListDelete(SqList &L,int i){
    if((i<1)||(i>L.length)) return 0;
    for(int j=i;j<=L.length;j++){
        L.elem[j-1]=L.elem[j];
    }
    --L.length;
    return 1;
}
//����Ԫ������λ��
int LocateElem(SqList L,int e){
    int i;
    for(i=0;i<L.length;i++){
        if(L.elem[i].data==e) return i+1;
    }
    return 0;
}
int main()
{
    SqList L;
    int i=0,temp,a,c,choose;
    double price;
    Elem e;
    string head_1,head_2,head_3;
    cout<<"1.����\n";
    cout << "2. ����\n";
	cout << "3. ȡֵ\n";
	cout << "4. ����\n";
	cout << "5. ����\n";
	cout << "6. ɾ��\n";
	cout << "7. ���\n";
	cout << "0. �˳�\n\n";
    choose=-1;
    while(choose !=0){
        cout<<"��ѡ��";
        cin>>choose;
        switch(choose){
            case 1:{
                if(InitList(L)){
                    cout<<"�����ɹ�!"<<endl<<endl;
                }
                else
                    cout<<"����˳���ʧ��"<<endl<<endl;
            } break;
            case 2:{
                cout<<"������Ҫ�����Ԫ�أ�";
                int i=0;
                L.elem = new Elem[MAXSIZE];
                if(!L.elem) return (OVERFLOW);
                for(i=0;i<n;i++){
                    cin>>L.elem[i].data;
                }
                L.length = i+1;
            } break;
            case 3:{

            }
        }
    }
    return 0;
}
