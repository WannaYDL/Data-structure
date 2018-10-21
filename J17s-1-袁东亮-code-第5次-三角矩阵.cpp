#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
/*
上三角一维转二维
b[15]={1,1,1,4,1,1,1,1,1,1,4,1,1,1,1}
转为二维
1 1 1 4 1
0 1 1 1 1
0 0 1 4 1
0 0 0 1 1
0 0 0 0 1
*/

int main()
{
    int b[15]={1,1,1,4,1,1,1,1,1,1,4,1,1,1,1};
    int a[6][6];
    memset(a,0,sizeof(a));
    int n=5;//矩阵边长
    int cnt=0;//读取b数组的位置
    for(int i=1;i<=5;i++){
        for(int j=i;j<=n;j++){
            a[i][j]=b[cnt++];
        }
    }
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}


/*
//上三角二维转一维
const int maxn=6;
int main()
{
    int k;
    int i,j;
    int a[maxn][maxn];
    int b[16];
    for(i=1;i<maxn;i++){
        for(int j=1;j<maxn;j++){
            if(i>j)a[i][j]=0;
            else a[i][j]=1;
            a[1][4]=4;a[3][4]=4;
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    for(i=1;i<maxn;i++){
        for(j=1;j<maxn;j++){
          if(i<=j){
                k=(i-1)*(2*(maxn-1)-i+2)/2+(j-i);
                b[k]=a[i][j];
            }
        }
    }
    for(int i=0;i<=5*6/2-1;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
*/

//下三角矩阵一维转二维
void xiasanjiao()
{
    int b[10]={1,1,1,1,0,1,0,0,0,1};
    int a[5][5];
    int n=4;
    memset(a,0,sizeof(a));
    int cnt=0;//记录读取b的位置
    for(int i=1;i<=n;i++){
        if(i==1)a[i][i]=b[cnt++];
        else{
            for(int j=1;j<=i;j++){
                a[i][j]=b[cnt++];
            }
        }
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
