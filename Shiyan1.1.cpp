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
//初始化
int InitList(SqList &L){
    L.elem = new Elem[MAXSIZE];
    if(!L.elem)
        return (OVERFLOW);
    L.length=0;
    return 1;
}
//插入
int ListInsert(SqList &L, int i, Elem e){
//在顺序表的第i个位置插入新的元素e 1<=i<=length+1
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
//取值
int GetElem(SqList &L,int i,Elem &e){
    if((i<1)||(i>L.length)) return 0;
    e=L.elem[i-1];
    return 1;
}
//删除
int ListDelete(SqList &L,int i){
    if((i<1)||(i>L.length)) return 0;
    for(int j=i;j<=L.length;j++){
        L.elem[j-1]=L.elem[j];
    }
    --L.length;
    return 1;
}
//查找元素所在位置
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
    cout<<"1.建立\n";
    cout << "2. 输入\n";
	cout << "3. 取值\n";
	cout << "4. 查找\n";
	cout << "5. 插入\n";
	cout << "6. 删除\n";
	cout << "7. 输出\n";
	cout << "0. 退出\n\n";
    choose=-1;
    while(choose !=0){
        cout<<"请选择：";
        cin>>choose;
        switch(choose){
            case 1:{
                if(InitList(L)){
                    cout<<"创建成功!"<<endl<<endl;
                }
                else
                    cout<<"创建顺序表失败"<<endl<<endl;
            } break;
            case 2:{
                cout<<"请输入要插入的元素：";
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
