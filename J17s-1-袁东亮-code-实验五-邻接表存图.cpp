#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int MVNum=100;
typedef struct ArcNode{
    int adjvex;
    struct ArcNode *nextarc;
}ArcNoce;
typedef struct VNode{
    int data;
    ArcNode *firstarc;
}VNode,AdjList[MVNum];
typedef struct {
    AdjList vertices;
    int vnum,anum;
}ALGraph;
/*创建邻接表存图*/
int CreatUDG(ALGraph &G)
{
    int i,j,k,v1,v2;
    cin>>G.vnum>>G.anum;
    for(i=0;i<G.vnum;i++){
        cin>>G.vertices[i].data;
        G.vertices[i].firstarc=NULL;
    }
    for(k=0;k<G.anum;k++){
        cin>>v1>>v2;
        if(v1>G.vnum||v2>G.vnum){
            cout<<"输入超界，无效输入！"<<endl;
            continue;
        }
        ArcNode *p1,*p2;
        p1=new ArcNode;
        p1->adjvex=v2;
        p1->nextarc=G.vertices[v1].firstarc;G.vertices[v1].firstarc=p1;
        p2=new ArcNode;
        p2->adjvex=v1;
        p2->nextarc=G.vertices[v2].firstarc;G.vertices[v2].firstarc=p2;
    }
}
void ShowUDG(ALGraph &G)
{
    for(int i=0;i<G.vnum;i++){

    }
}
