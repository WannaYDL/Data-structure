#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#include <cstring>
#include <iomanip>
using namespace std;
const int maxn = 30;
const int INF=32767;
int G[maxn][maxn];//二维数组
int path[maxn];//路径数组
int pathL[maxn];
int S[maxn],D[maxn];
int st,en;//起点，终点

struct EDGE{
	int next;   //下一条边的存储下标
	int to;     //这条边的终点
	int val;      //权值
};
EDGE edges[maxn];
int cnt=0;
int head[maxn];  //head[i]表示以i为起点的第一条边
void Add(int u, int v, int val) {  //起点u, 终点v, 权值w
	edges[++cnt].next = head[u];
	edges[cnt].val = val;
	edges[cnt].to = v;
	head[u] = cnt;    //第一条边为当前边
}
void InPutLian(int n)
{
    int a,b,val,x;
    cout<<"请输入边数：";
    cin>>x;
    for(int i=1;i<=x;i++){
        cin>>a>>b>>val;
        if(a>n&&b>n)
            break;
        Add(a,b,val);
        Add(b,a,val);
    }
}
void ShowLian(int n)
{
    for(int j=1;j<=n;j++)
    for(int i=head[j]; i!=0; i=edges[i].next) {//i开始为第一条边，每次指向下一条(以0为结束标志)若下标从0开始，next应初始化-1
		cout << "Start: " << j <<"  ";
		cout << "End: " << edges[i].to <<"  ";
		cout << "Val: " << edges[i].val <<"  "<<"Next: "<<edges[i].next<< endl;

	}
}

int DIJLian(int v0,int n)
{
   //初始化各参数
    int V;
    for(V=1;V<=n;V++){
        S[V]=0;
        D[V]=INF;
        pathL[V]=-1;
        //cout<<path[v]<<" ";
    }
//cout<<"pathL[1]"<<pathL[1]<<endl;
   // cout<<endl;
    S[v0]=1;
    D[v0]=0;
    //对剩余的点找到路径最小的边的终点加入S集合
    for(int i = head[v0]; i!=0; i = edges[i].next){
        int v = edges[i].to, w = edges[i].val;
        D[v] = w;
        if(w<INF){
            pathL[v]=v0;
        }
    }

    for(int t = 1; t < n; t++){
        int p,min_p = INF;
        for(int i = 1; i <= n; i++){
            if(S[i] == 0 && D[i] < min_p){
                 min_p = D[i]; p = i;
            }
        }

        S[p] = 1;
        for(int i = head[p]; i!=0; i = edges[i].next){
            int v = edges[i].to, w = edges[i].val;
            if(D[p] + w < D[v]){
                D[v] = D[p] + w;
                pathL[v]=p;
                //cout<<"hear!  "<<pathL[1]<<endl;
            }
        }

    }
}
void ShowPathL(int n){
    for(int i=1;i<=n;i++){
        cout<<pathL[i]<<" ";
    }
    cout<<endl;
}
int PrintPathL(int n)
{
    int t;
    stack<int>sta;
    sta.push(n);
    while(n!=-1){
        t=pathL[n];
        n=t;
        sta.push(t);
    }
    sta.pop();
    while(!sta.empty()){
        int q;
        q=sta.top();
        sta.pop();
        if(!sta.empty()){
            cout<<q<<"->";
        }
        else{
            cout<<q;
        }
    }
}


void ShowPath(int n){
    for(int i=1;i<=n;i++){
        cout<<path[i]<<" ";
    }
    cout<<endl;
}
void init(int n)
{
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            G[i][j]=INF;
        }
    }
}
void InPutJV(int n){
    int a,b,w,x;
    cout<<"请输入边数：";
    cin>>x;
    for(int i=1;i<=x;i++){
        cin>>a>>b>>w;
        if(a>n&&b>n)
            break;
        G[a][b]=w;
        G[b][a]=w;
    }
}
void ShowUDG(int n)
{
    //二维数组遍历
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<setw(7)<<G[i][j];
        }
        cout<<endl;
    }
}
int DIJ(int v0,int n)
{
   //初始化各参数
    int v;
    for(v=1;v<=n;v++){
        S[v]=0;
        D[v]=G[v0][v];
        if(D[v]<INF) path[v]=v0;
        else path[v]=-1;
        //cout<<path[v]<<" ";
    }
   // cout<<endl;
    S[v0]=1;
    D[v0]=0;
    //对剩余的点找到路径最小的边的终点加入S集合
    int i;  //计数n-1 次
    int Min,u;
    for(i=2;i<=n;i++){
        Min=INF;
        for(u=1;u<=n;u++){
            if(!S[u]&&D[u]<Min){
                v=u;Min=D[u];
            }
        }
        S[v]=1;
        //更新D[]数组的值
        for(u=0;u<=n;u++){
            if(!S[u]&&(D[v]+G[v][u]<D[u])){
                D[u]=D[v]+G[v][u];
                path[u]=v;
            }
        }
    }
}


int PrintPath(int n)
{
    int t,lent=0;
    stack<int>sta;
    sta.push(n);
    while(n!=-1){
        t=path[n];
        lent+=G[t][n];
        n=t;
        sta.push(t);
    }
    sta.pop();
    while(!sta.empty()){
        int q;
        q=sta.top();
        sta.pop();
        if(!sta.empty()){
            cout<<q<<"->";
        }
        else{
            cout<<q;
        }
    }
    return lent;
}

int main()
{

    int n,lent;
    cout<<"请输入总结点数: ";
    cin>>n;
    cout<<"请输入最短路径的起始和结束结点: ";
    cin>>st>>en;
    init(n);
    cout<<"请输入数字来代表要执行的操作\n";
    cout<<"邻接矩阵实现： 1\n";
    cout<<"邻接表实现：2\n";
    cout<<"退出系统：0\n";
    while(1){
        int choose=-1;
        cout<<"请输入操作数字：";
        cin>>choose;
        if(choose==0) {
                cout<<"退出系统！"<<endl;
                break;
        }
        switch(choose)
        {
            case 1: {
                cout<<"请输入边数及边的起点、终点和边的权值\n";
                //矩阵
                InPutJV(n);
                cout<<"打印图\n";
                ShowUDG(n);
                DIJ(st,n);
                cout<<"path[]数组："<<endl;
                ShowPath(n);
                cout<<"最短路径为："<<endl;
                lent=PrintPath(en);
                cout<<endl;
                cout<<lent<<endl;

            }break;
            case 2:{
                cout<<"请输入边数及边的起点、终点和边的权值\n";
                InPutLian(n);
                cout<<"链式前向星打印：";
                ShowLian(n);
                DIJLian(st,n);
                cout<<"pathL[]数组为";
                ShowPathL(n);
//                cout<<"最短路径为："<<endl;
//                PrintPath(en);
//                cout<<endl<<endl;
            }break;
        }
    }

    return 0;
}
//    cout<<"样例："<<endl;
//    cout<<"1 3 5"<<endl;
//    cout<<"1 4 30"<<endl;
//    cout<<"2 1 2"<<endl;
//    cout<<"3 2 15"<<endl;
//    cout<<"3 6 7"<<endl;
//    cout<<"5 4 4"<<endl;
//    cout<<"6 4 10"<<endl;
//    cout<<"6 5 18"<<endl;


/*
1 3 5
1 4 30
2 1 2
3 2 15
3 6 7
5 4 4
6 4 10
6 5 18
*/
