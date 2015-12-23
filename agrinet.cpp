/*
TASK:agrinet
ID:pen_wan1
LANG:C++
*/

#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <string.h>
//A:vertexes of MST��С������, V-A: the others
using namespace std;
int adj[100+5][100+5];
int N;
int key[100+5];//����B�еĽڵ㵽����A�е���СȨ��
int parent[100+5];//������¼��С��������
int weight; //��¼��С��������Ȩ��

int main()
{
    freopen("agrinet.in","r",stdin);
    freopen("agrinet.out","w",stdout);
    cin>>N;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>adj[i][j];
//Prim�㷨
    //��ʼ��
    for(int i=1;i<=N;i++){
        key[i]=1000000; }//��ֵΪ������
         
    key[0]=0;  //�ӵ�0���ڵ㿪ʼ����MST,���ѽڵ�0���뼯��A�У�����ΪV-A
    int visit[100+5];//��¼�Ƿ���ʹ�,�ڵ����ڼ���A��
    memset(visit,0,sizeof(visit));

    for(int i=0;i<N;i++){
        //�ҵ�V-A��A��һ����СȨ�ؽڵ�
        int u,minKey=1000000;
        for(int j=0;j<N;j++)
            if(!visit[j]&&key[j]<minKey) {minKey=key[j],u=j;}
        visit[u]=1; //�ڵ���뼯��A��
        weight=weight+minKey;
        //����V-A��ͨ��u�뼯��A�������Ķ���Ȩ(AΪ��С�������ļ���)
        for(int j=0;j<N;j++)
            if(!visit[j]&&adj[u][j]&&adj[u][j]<key[j])
               { key[j]=adj[u][j];parent[j]=u;}
    }
	
    cout << weight << endl;
    return 0;
}
