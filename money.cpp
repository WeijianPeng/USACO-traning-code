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
//long long  F[25+5][10000+5]; //ǰi�ֻ��ҿ��Բ�������ΪN�ķ�����
long long  FF[10000+5];

int main()
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    cin>>V>>N;
    for(int i=1;i<=V;i++)
        cin>>VMoney[i];
	
/*     //��ȫ����
    for(int i=0;i<=N/VMoney[1];i++)
        F[1][VMoney[1]*i]=1;
    for(int i=1;i<=V;i++)
        F[i][0]=1;
	
    for(int i=2;i<=V;i++)//ǰi�ֻ���
        for(int j=1;j<=N;j++){//��ֵΪj
            F[i][j]=F[i-1][j];//��VMoneu[i]����jʱ���Ǵ�ֵ������ִ������ѭ���顣
            for(int k=1;k<=j/VMoney[i];k++){//������i�ֻ���ʱ�����ķ�����
                    F[i][j]+=F[i-1][j-k*VMoney[i]];
            }
        }
     cout<<F[V][N]<<endl; */

    //����
    for(int i=0;i<=N/VMoney[1];i++)
        FF[VMoney[1]*i]=1;
    for(int i=2;i<=V;i++)//ǰi�ֻ���
        for(int j=VMoney[i];j<=N;j++){//��ֵΪj            //F[j]=F[j];
				FF[j] +=FF[j-VMoney[i]];
        }
     cout<<FF[N]<<endl;

    return 0;
}
