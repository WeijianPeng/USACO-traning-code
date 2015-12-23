/*
TASK:inflate
ID:pen_wan1
LANG:C++
*/

#include <iostream>
#include <cstdio>

using namespace std;
int mymax(int i,int j){
    if (i>j) return i;
    return j;
}

int M,N;//竞赛时间（等价背包体积），题目种类数目
int W[10000+5],C[10000+5];//每种题目的价值和耗时
int F[10000+5];//在额定时间内，能取得的最多分（价值）
int main()
{

    freopen("inflate.in","r",stdin);
    freopen("inflate.out","w",stdout);

    cin>>M>>N;
    for(int i=1;i<=N;i++){
        cin>>W[i]>>C[i];
    }

//完全背包，（滚动数组节省空间）
    //初始化，因为总时间必须是M（背包装满）
    // F[0]=0;
    // for(int i=1;i<=M;i++){F[i]=-10000;}

    for(int i=1;i<=N;i++){
        for(int v=C[i];v<=M;v++)
            F[v]=mymax(F[v],F[v-C[i]]+W[i]);
    }
    cout<<F[M]<<endl;
    return 0;
}