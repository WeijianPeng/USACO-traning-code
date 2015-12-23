/*
ID:pen_wan1
LANG:C++
TASK:money
*/

#include <iostream>
#include <cstdio>
using namespace std;

int VMoney[25];
int V,N;
//long long  F[25+5][10000+5]; //前i种货币可以产生数量为N的方案数
long long  FF[10000+5];

int main()
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    cin>>V>>N;
    for(int i=1;i<=V;i++)
        cin>>VMoney[i];
	
/*     //完全背包
    for(int i=0;i<=N/VMoney[1];i++)
        F[1][VMoney[1]*i]=1;
    for(int i=1;i<=V;i++)
        F[i][0]=1;
	
    for(int i=2;i<=V;i++)//前i种货币
        for(int j=1;j<=N;j++){//数值为j
            F[i][j]=F[i-1][j];//当VMoneu[i]大于j时就是此值，否则执行下面循环块。
            for(int k=1;k<=j/VMoney[i];k++){//包含第i种货币时新增的方案数
                    F[i][j]+=F[i-1][j-k*VMoney[i]];
            }
        }
     cout<<F[V][N]<<endl; */

    //法二
    for(int i=0;i<=N/VMoney[1];i++)
        FF[VMoney[1]*i]=1;
    for(int i=2;i<=V;i++)//前i种货币
        for(int j=VMoney[i];j<=N;j++){//数值为j            //F[j]=F[j];
				FF[j] +=FF[j-VMoney[i]];
        }
     cout<<FF[N]<<endl;

    return 0;
}
