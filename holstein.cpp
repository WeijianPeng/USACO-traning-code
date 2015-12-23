/*
ID:pen_wan1
LANG:C++
TASK:holstein
*/


#include<iostream>
#include<cstdio>

using namespace std;

int N,M;
int v[25+5];
int vv[1000+10][1000+10];

int vis[25+5];
int temp[25];

int rst=25;

int isok(int *A,int cur){
	int i,j,sum;
	for (i=0;i<N;i++)
	{
		sum=0;
		for (j=0;j<cur;j++){
			sum=sum+vv[A[j]][i];
		}

		if (sum<v[i])
	        return 0;
	}
	return 1;
}


void print_subset(int n, int* A, int cur) {//求元素的子集
	int i;

 	
	if(isok(A,cur)&&cur<rst){
		rst=cur;
		for(i = 0; i<cur+1; i++) {
			vis[i]=A[i];
		} 
	}

	int s = cur ? A[cur-1]+1 : 0; // 确定当前元素的最小可能值
	for( i = s; i < n; i++) {
		A[cur] = i;
		print_subset(n, A, cur+1); // 递归构造子集
	}
}


int main()
{
	freopen("holstein.in","r",stdin);
	freopen("holstein.out","w",stdout);

	cin>>N;
	int i,j;
	for (i=0;i<N;i++)
	{
		cin>>v[i];
	}
	cin>>M;
	for (i=0;i<M;i++)
		for(j=0;j<N;j++)
		{
			cin>>vv[i][j];
		}


	print_subset(M,temp,0);

	cout<<rst;
	for (i=0;i<rst;i++)
	{cout<<" "<<(vis[i]+1);}

	cout<<endl;

	return 0;
}