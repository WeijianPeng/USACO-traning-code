/*
TASK:comehome
LANG:C++
ID:pen_wan1
*/

//Dijkstra实现，利用了最小优先队列
#include <iostream>
#include <cstdio>
#include <vector>
#include<ctype.h>
#include<string.h>
#include<algorithm>

using namespace std;

typedef struct node Node;
struct node{
    int num;
    int wei;
};
int min(int a,int b){
    if(a<b)
    return a;
    return b;
}
int dst[26+26+5];
int cmp(int a,int b){
    return dst[a]<dst[b];
}

int main()
{
    char pas[26+26+5];    //pasture谷仓（包含是否有牛的信息）
    int Que[26+26+5];

    vector < vector <node> > adj(26+26+5); //path
    int nPath;
    freopen("comehome.in","r",stdin);
freopen("comehome.out","w",stdout);
    cin>>nPath;
    for(int i=0;i<nPath;i++){
        char A,B;int j;
        cin>>A>>B>>j;

        int ANum,BNum;
        ANum=tolower(A)-'a'+1;
        BNum=tolower(B)-'a'+1;
        if(A<'a'){
            ANum=ANum+26;;//字母序
        }
        if(B<'a'){
            BNum=BNum+26;;//字母序
        }

        pas[ANum]=A;
        pas[BNum]=B;

        Node adjA; adjA.num=BNum,adjA.wei=j;
        adj[ANum].push_back(adjA);

        Node adjB;adjB.num=ANum,adjB.wei=j;
        adj[BNum].push_back(adjB);
    }

    for(int i=1;i<=52;i++)
        {Que[i]=i;dst[i]=1000000;}
    //Dijkstra
    dst[52]=0;
    int visit[52+5];//标志是否在最短路径的集合
    int vstNum=1;
     memset(visit,0,sizeof(visit));

    while (vstNum<=52){
            int u;int mini=100000;
            for(int k=1;k<=52;k++){
                if(!visit[k]&&dst[k]<mini) {mini=dst[k];u=k;}//??? k?
            }
            visit[u]=1;
            for(unsigned int i=0;i<adj[u].size();i++){//v-->Que
                if(dst[adj[u][i].num]>dst[u]+adj [u][i].wei)
                    dst[adj[u][i].num]=dst[u]+adj[u][i].wei;
            }
            vstNum++;
    }
    int mysort[52+5];
    for(int i=1;i<53;i++){
        mysort[i]=i;
    }

    sort(mysort+1,mysort+52,cmp);

    for(int i=1;i<=52;i++){
        if(pas[mysort[i]]<'Z'){
            for(int j=i;j<=52&&dst[mysort[j]]==dst[mysort[i]]&&pas[mysort[j]]<'Z';j++)
                cout<<pas[mysort[j]]<<" "<<dst[mysort[j]]<<endl;
            break;
        }
    }
    return 0;
}

// #include <iostream>
// #include <cstdio>
// #include <vector>
// #include<ctype.h>
// #include<string.h>
// #include<algorithm>

// using namespace std;

// typedef struct node Node;
// struct node{
    // int num;
    // int wei;
// };
// int min(int a,int b){
    // if(a<b)
    // return a;
    // return b;
// }

// //Heap.cpp
// //最小优先队列，Q为节点序号，d为对应节点的关健值（卫星数）
// //Q[0]不要
// //只实现了minHeapify、buildHeapify和extractMin  （insert，Minimum，increaseKey未实现）
// void minHeapify(int *Que,int *Key,int i,int heapSize){//维护最小堆，smallest,l,r,i都是优先队列元素的下标，范围是从1 ~ heapSize
	// int l = 2*i;   //右孩子
	// int r = 2*i+1; //左孩子
	// int smallest;
	// if(l<=heapSize && Key[Que[l]] < Key[Que[i] ]){
		// smallest = l;
	// }
	// else{
		// smallest = i;
	// }

	// if(r<=heapSize && Key[ Que[r] ] < Key[ Que[smallest] ]){
		// smallest = r;
	// }
	// if(smallest!=i){
		// int temp = Que[i];
		// Que[i] = Que[smallest];
		// Que[smallest] = temp;
	    // minHeapify(Que,Key,smallest,heapSize);
	// }
// }

// void buildHeapify(int *Que,int *Key,int heapSize){
	// for(int i=heapSize/2;i>=1;i--){//从有孩子的节点自底向上建最小堆
		// minHeapify(Que,Key,i,heapSize);  //维护最小堆是自顶向下的顺序
	// }
// }

// int extractMin(int *Que,int *Key, int *heapSize){//摘取优先队列中最小元素的内容，这里返回图中顶点的标号(0 ~ G.vexnum-1)，这些标号是保存在Q[1..n]中的
	// if(*heapSize<1){
		// cout<<"heap underflow!"<<endl;
	// }
	// int min = Que[1];
	// Que[1] = Que[*heapSize];
	// (*heapSize)--;
	// minHeapify(Que,Key,1,*heapSize);
	// return min;
// }

// void decreaseKey(int *Que,int *Key,int i,int value){
    // if (value>Key[i])
        // cout<<"erro,new key value is bigger than current key";
    // Key[i]=value;
    // int j;
    // for(j=1;Que[j]!=i;j++);


    // while (j>1&&Key[Que[j/2]]>Key[Que[j]]){
        // int temp =Que[j];
		// Que[j] = Que[j/2];
		// Que[j/2]= temp;
		// j=j/2;
    // }
// }
 // int dst[26+26+5];
// //========heap end===========
// int cmp(int a,int b){
    // return dst[a]<dst[b];
// }

// int main()
// {
    // char pas[26+26+5];    //pasture谷仓（包含是否有牛的信息）
    // int Que[26+26+5];

    // vector < vector <node> > adj(26+26+5); //path
    // int nPath;
    // freopen("comehome.in","r",stdin);
    // freopen("comehome.out","w",stdout);
    // cin>>nPath;
    // for(int i=0;i<nPath;i++){
        // char A,B;int j;
        // cin>>A>>B>>j;

        // int ANum,BNum;
        // ANum=tolower(A)-'a'+1;
        // BNum=tolower(B)-'a'+1;
        // if(A<'a'){
            // ANum=ANum+26;;//字母序
        // }
        // if(B<'a'){
            // BNum=BNum+26;;//字母序
        // }

        // pas[ANum]=A;
        // pas[BNum]=B;

        // Node adjA; adjA.num=BNum,adjA.wei=j;
        // adj[ANum].push_back(adjA);

        // Node adjB;adjB.num=ANum,adjB.wei=j;
        // adj[BNum].push_back(adjB);
    // }

    // for(int i=1;i<=52;i++)
        // {Que[i]=i;dst[i]=1000000;}
    // //Dijkstra
    // dst[52]=0;
    // int heapSize=52;
    // buildHeapify(Que,dst,heapSize);
    // while (heapSize>=1){
            // int u=extractMin(Que,dst,&heapSize);//heapSize--;
            // for(unsigned int i=0;i<adj[u].size();i++){//v-->Que
                // if(dst[adj[u][i].num]>dst[u]+adj[u][i].wei)
                    // //dst[adj[u][i].num]=dst[u]+adj[u][i].wei;
                    // decreaseKey(Que,dst,adj[u][i].num,dst[u]+adj[u][i].wei);
            // }
    // }
    // int mysort[52+5];
    // for(int i=1;i<53;i++){
        // mysort[i]=i;
    // }

    // sort(mysort+1,mysort+52,cmp);

    // for(int i=1;i<=52;i++){
        // if(pas[mysort[i]]<'Z'){
            // for(int j=i;j<=52&&dst[mysort[j]]==dst[mysort[i]]&&pas[mysort[j]]<'Z';j++)
                // cout<<pas[mysort[j]]<<" "<<dst[mysort[j]]<<endl;
            // break;
        // }
    // }
    // return 0;
// }
