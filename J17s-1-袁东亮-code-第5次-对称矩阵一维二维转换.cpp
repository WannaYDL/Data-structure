#include <iostream>
#include <cstring>
using namespace std;
/*
已知一维数组b[10]={1,1,1,1,0,1,0,0,0,1}
写出二维数组
1 1 1 0
1 1 0 0
1 0 1 0
0 0 0 1
*/
int main()
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
                a[j][i]=a[i][j]=b[cnt++];
            }
        }
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}




/*
//二维转一维
const int maxn=6;
int main()
{
    int k;
    int i,j;
    int a[maxn][maxn];
    int b[maxn*maxn];
    memset(a,0,sizeof(a));
    for(i=1;i<maxn;i++){
        a[i][i]=1;
    }
    for(i=1;i<maxn;i++){
        for(j=1;j<maxn;j++){
            if(i>=j){
                k=(i*(i-1)/2)+j-1;
                b[k]=a[i][j];
            }
            else if(i<j){
                k=j*(j-1)/2+i-1;
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

/*
int lis[21];
void findn(){
    lis[0]=1;
    int n=21;
    int cnt=1;
    while(cnt<n){
        lis[cnt++]=cnt*(cnt+1)/2;
    }
    findn();
    int n;
    int lenb;
    cout<<"请输入一维数组的长度n：";
    cin>>lenb;
    for(int i=0;i<21;i++){
        if(lis[i]==lenb){
            n=i+1;
        }
    }
    int *b=new int[lenb];
    cout<<"请输入数组元素：";
    for(int i=0;i<lenb;i++){
        cin>>b[i];
    }
    int a[n+2][n+2];
}


*/
