#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef struct Josephus{
    int num;
    int count;
    //int t;
};
//��ʼ��
void InitJosephus(Josephus man[],int n)
{
    int i;
    for(i=0;i<n;i++){
        man[i].num=i+1;
        man[i].count=0;//���е����
    }
}
//Լɪ���������
void displayJosephus(Josephus man[],int n)
{
    int i;
    cout<<"���Լɪ�����е�˳��λ����š������������\n";
    for(i=0;i<n;i++){
        cout<<man[i].num<<"  "<<man[i].count<<endl;
    }
}
// ģ�ⱨ��,n���ˣ�mΪ�ڵ�
void baoshu(Josephus man[], int n, int m)
{
   int counter=1;  //���м�����
    int i=0;   //����������
    int pos=-1;  //λ�ü�����
    while(counter<=n) //��N������ģ��ѭ������
    {
        do{
            pos=(pos+1) % n;	//���࣬���л�״����
            if(man[pos].count==0)	//�����pos��δ����
                i++;        //����
            if(i==m)	//����M����
            {
                i=0;
                m++;    //��ʼ�����������ִ�1��ʼ����
                break;
            }
        }while(1);
        man[pos].count=counter;  //����������
        counter++;
    }
}
//����������
void sort_by_count(Josephus man[],int n)
{
    int i,j;
    Josephus t;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(man[i].count>man[j].count){
                t=man[i];
                man[i]=man[j];
                man[j]=t;
            }
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    Josephus man[n];
    InitJosephus(man,n);
    baoshu(man,n,m);
    displayJosephus(man,n);
    //sort_by_count(man,n);
    //displayJosephus(man,n);
}
