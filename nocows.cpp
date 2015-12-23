/*
ID:pen_wan1
LANG:C++
TASK:nocows
*/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <math.h>
using namespace std;

int N,K;
unsigned int table[200][100]; //# node,# height;
unsigned int smalltrees[200][100];


int main()
{
    ifstream in("nocows.in");
    ofstream out("nocows.out");
    in>>N>>K;

    table[0][0]=1;
    table[0][1]=0;
   // table[2][0]=0;
    table[2][1]=1;
    smalltrees[0][0]=1; //
    //smalltrees[0][1]=1;
    //smalltrees[2][0]=1;

    for(int i=0;i<N;i=i+2){//从5个节点开始
        for(int j=1;j<K;j++){
            smalltrees[i][j]+=smalltrees[i][j-1];
            if((i>=2&&j>=2&&j>=ceil(log10(i+1+1)/log10(2))-1)&&(2*j+1<=i+1)){//高度j>=ceil(log10(i+1+1)/log10(2))-1 ,j<=
                for(int k=0;k<=i-2;k=k+2){
                    table[i][j] =(table[i][j]+smalltrees[k][j-2]*table[i-1-k-1][j-1])%9901;
                    // 左子树深度小于j-1，右子树深度为j-1
                    table[i][j] =(table[i][j]+table[k][j-1]*smalltrees[i-1-k-1][j-2])%9901;
                    // 左子树深度为j-1，右子树深度小于j-1
                    table[i][j] =(table[i][j]+table[k][j-1]*table[i-1-k-1][j-1])%9901;
                    // 左右子树深度都为j-1
                }
            }
        if(i>=2&j>=1) smalltrees[i][j]=(smalltrees[i][j]+table[i][j])%9901;//更新smalltrees
        }
    }
    out<<table[N-1][K-1]<<endl;

    return 0;
}
