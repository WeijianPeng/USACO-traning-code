/*
ID:pen_wan1
LANG:C++
TASK:subset
*/
#include<iostream>
#include<cstdio>

using namespace std;
//“从原集合中选出n个物品，使这n个物品恰好放满容量为sum/2的背包的方案总数”。
int cnt;
int N;
int sum,i_sum;
int data[39+5];
unsigned int  F[39+5][(1+39)*39/(2*2)+5];


int main(){
	
	freopen("subset.in","r",stdin);
	freopen("subset.out","w",stdout);
	cin>>N;
	int i,v_sum;	
	
	sum=(1+N)*N/2;
	
    if (sum%2==1){
		cout<<0<<endl;
		return 0;
    }
	else{
		//F[0; 0...V ]= 0
		F[1][1]=1;
		F[1][0]=1;
		for(i=2;i<=N;i++){
			//F[i,j]表示取前i个数，使集合总元素数和为j的方案数
			for(v_sum=0;v_sum<i;v_sum++)
				F[i][v_sum]=F[i-1][v_sum];//集合总和v_sum小于i,不能将数i加入集合;F[i][v_sum]为可行方案数

			for(v_sum=i;v_sum<=sum/2;v_sum++) {//计算所有空间大小i-N,目前i个数可以得到的和
				F[i][v_sum]=F[i-1][v_sum]+F[i-1][v_sum-i];
				
				}
		}
		
	cout<<F[N][sum/2]/2<<endl;
	}
		return 0;
	}