/*
TASK:agrinet
ID:pen_wan1
LANG:C++
*/

#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <string.h>
//A:vertexes of MST最小生成树, V-A: the others
using namespace std;
int adj[100+5][100+5];
int N;
int key[100+5];//集合B中的节点到集合A中的最小权重
int parent[100+5];//用来记录最小生成树；
int weight; //记录最小生成树的权重

int main()
{
    freopen("agrinet.in","r",stdin);
    freopen("agrinet.out","w",stdout);
    cin>>N;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>adj[i][j];
//Prim算法
    //初始化
    for(int i=1;i<=N;i++){
        key[i]=1000000; }//赋值为正无穷
         
    key[0]=0;  //从第0个节点开始生成MST,即把节点0加入集合A中，其余为V-A
    int visit[100+5];//记录是否访问过,节点属于集合A中
    memset(visit,0,sizeof(visit));

    for(int i=0;i<N;i++){
        //找到V-A到A的一个最小权重节点
        int u,minKey=1000000;
        for(int j=0;j<N;j++)
            if(!visit[j]&&key[j]<minKey) {minKey=key[j],u=j;}
        visit[u]=1; //节点加入集合A中
        weight=weight+minKey;
        //更新V-A中通过u与集合A的相连的顶点权(A为最小生成树的集合)
        for(int j=0;j<N;j++)
            if(!visit[j]&&adj[u][j]&&adj[u][j]<key[j])
               { key[j]=adj[u][j];parent[j]=u;}
    }
	
    cout << weight << endl;
    return 0;
}
