#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int INF=32767;
const int maxn=100;
typedef char Ver;
typedef int Arc;
Arc a[maxn][maxn];
/*邻接矩阵建图*/
typedef struct
{
    Arc arcs[maxn][maxn];
    int vnum,anum;
}AMGraph;
/*邻接矩阵建图*/
void CreatG(AMGraph &G)
{
    int i,j,k,v1,v2,w;
    cout<<"请输入图G的节点数和边数：";
    cin>>G.vnum>>G.anum;
    G.vnum++;
    cout<<"初始化！"<<endl;
    for(i=1;i<=G.vnum;i++){
        for(j=1;j<=G.vnum;j++){
            G.arcs[i][j]=INF;
        }
    }
    cout<<"请输入边连接的两个点及边权："<<endl;
    for(k=1;k<=G.anum;k++){
        cin>>v1>>v2>>w;
        if(v1>G.vnum||v2>G.vnum){
            cout<<"输入超界，无效输入！"<<endl;
        }
        G.arcs[v1][v2]=w;
        G.arcs[v2][v1]=w;
    }
    G.arcs[1][1]=250;
    cout<<"打印图"<<endl;
    for(i=1;i<=G.vnum;i++){
        for(j=1;j<=G.vnum;j++){
            cout<<G.arcs[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int i,j;
    AMGraph G;
    CreatG(G);
    return 0;
}
