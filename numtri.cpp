/*
ID:pen_wan1
LANG:C++
TASK:numtri
*/

#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

#define max(a,b) a>b ? a:b

int num[1000][1000],f[1000];

int main(){
	freopen("numtri.in","r",stdin);
	freopen("numtri.out","w",stdout);

	int R;
	int i,j;
	scanf("%d",&R);
	for (i=0;i<R;i++)
		for(j=0;j<i+1;j++)
			scanf("%d",&num[i][j]);

	//memset(f,0,sizeof(f[0])*R);


	for (i=0;i<R;i++)
		f[i]=num[R-1][i];

	for (i=R-1-1;i>=0;i--)
		for (j=0;j<=i;j++)
		{
			int t=max(f[j],f[j+1]);
			f[j]=t+num[i][j];
		}

cout<<f[0]<<endl;

return 0;

}