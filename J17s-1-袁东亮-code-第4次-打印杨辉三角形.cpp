#include <iostream>
#include <queue>
using namespace std;
//����ʵ��
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
    cout<<1<<" "<<endl;     //�����һ�е�1
    q.push(1);
    int s1,s2;
    for(int i=2;i<=n;i++){

        s1 = 0;
        for(int j=1;j<=i-1;j++){
            s2 = q.front();
            q.pop();         //����
            cout<<s1+s2<<" ";
            q.push(s1+s2);
            s1 = s2;         //s1��������ǰһ����
        }
        cout<<1<<endl;      //���ÿ�����һ��1
        q.push(1);
    }
}

int main(){
    int n,choose=-1;
    while(choose!=0){
        cout<<"��ѡ��ʵ�ַ�ʽ��1�����飻2������;0���˳�"<<endl;
        cin>>choose;
        if(choose==0){
            break;
        }
        cout<<"������������ǵ�������"<<endl;
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
