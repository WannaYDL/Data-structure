#include <iostream>
#include <queue>
using namespace std;
//数组实现
void PrintS(int n){
    int a[n+1][n+1];
    for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++){
        a[i][j]=0;
    }
    a[1][1]=1;
    for(int i=2;i<=n;i++)
    for(int j=1;j<=n;j++){
        if(j==1){
            a[i][j]=a[i-1][j];
        }
        else{
            a[i][j]=a[i-1][j]+a[i-1][j-1];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++){
            if(a[i][j]!=0)
                cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

void print_Triangle(int n){
    queue<int>q;
    cout<<1<<" "<<endl;     //输出第一行的1
    q.push(1);
    int s1,s2;
    for(int i=2;i<=n;i++){

        s1 = 0;
        for(int j=1;j<=i-1;j++){
            s2 = q.front();
            q.pop();         //出队
            cout<<s1+s2<<" ";
            q.push(s1+s2);
            s1 = s2;         //s1保留的是前一个数
        }
        cout<<1<<endl;      //输出每行最后一个1
        q.push(1);
    }
}

int main(){
    int n,choose=-1;
    while(choose!=0){
        cout<<"请选择实现方式：1、数组；2、队列;0、退出"<<endl;
        cin>>choose;
        if(choose==0){
            break;
        }
        cout<<"请输入杨辉三角的行数："<<endl;
        cin>>n;
        switch(choose){
        case 1:{
                PrintS(n);
            }break;
        case 2:{
            print_Triangle(n);
            }break;
        }
    }
    return 0;
}
