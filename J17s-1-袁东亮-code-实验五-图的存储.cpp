#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int INF=32767;
const int maxn=100;
typedef char Ver;
typedef int Arc;
Arc a[maxn][maxn];
/*�ڽӾ���ͼ*/
typedef struct
{
    Arc arcs[maxn][maxn];
    int vnum,anum;
}AMGraph;
/*�ڽӾ���ͼ*/
void CreatG(AMGraph &G)
{
    int i,j,k,v1,v2,w;
    cout<<"������ͼG�Ľڵ����ͱ�����";
    cin>>G.vnum>>G.anum;
    G.vnum++;
    cout<<"��ʼ����"<<endl;
    for(i=1;i<=G.vnum;i++){
        for(j=1;j<=G.vnum;j++){
            G.arcs[i][j]=INF;
        }
    }
    cout<<"����������ӵ������㼰��Ȩ��"<<endl;
    for(k=1;k<=G.anum;k++){
        cin>>v1>>v2>>w;
        if(v1>G.vnum||v2>G.vnum){
            cout<<"���볬�磬��Ч���룡"<<endl;
        }
        G.arcs[v1][v2]=w;
        G.arcs[v2][v1]=w;
    }
    G.arcs[1][1]=250;
    cout<<"��ӡͼ"<<endl;
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
