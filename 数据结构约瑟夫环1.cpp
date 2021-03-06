#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef struct Josephus{
    int num;
    int count;
    //int t;
};
//初始化
void InitJosephus(Josephus man[],int n)
{
    int i;
    for(i=0;i<n;i++){
        man[i].num=i+1;
        man[i].count=0;//出列的序号
    }
}
//约瑟夫排列输出
void displayJosephus(Josephus man[],int n)
{
    int i;
    cout<<"输出约瑟夫排列的顺序：位置序号———出列序号\n";
    for(i=0;i<n;i++){
        cout<<man[i].num<<"  "<<man[i].count<<endl;
    }
}
// 模拟报数,n个人，m为节点
void baoshu(Josephus man[], int n, int m)
{
   int counter=1;  //出列记数器
    int i=0;   //报数记数器
    int pos=-1;  //位置记数器
    while(counter<=n) //在N个人中模拟循环报数
    {
        do{
            pos=(pos+1) % n;	//求余，进行环状处理
            if(man[pos].count==0)	//若编号pos还未出列
                i++;        //报数
            if(i==m)	//报数M的人
            {
                i=0;
                m++;    //初始化记数器，又从1开始报数
                break;
            }
        }while(1);
        man[pos].count=counter;  //保存出列序号
        counter++;
    }
}
//按出列排序
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
