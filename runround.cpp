/*
ID:pen_wan1
LANG:C++
TASK:runround
*/

#include <iostream>
#include<string.h>
#include<cstdio>

using namespace std;

int M;
int vis[9+1];
int flag=1;
int rst;

void isrunaround(int x){
	char str1[10];
	int vv[10];
	memset(vv,0,10*4);
	int i,j,len,next_k,k=0,cnt=0;
	
	sprintf(str1,"%d",x);//数字输出到字符串  sscanf 用法
	len=strlen(str1);

	if(x==122) 
		x=122;
	for (i=0;i<len;i++)
	{	vv[str1[i]-48]=vv[str1[i]-48]+1;	
		if (vv[0]==1||vv[str1[i]-48]==2) return;
	}

	for (;;)
	{	cnt++;
		j=str1[k]-48;
		vis[k]=1;
		next_k=(k+j)%len;	
		if (vis[next_k]==1&&next_k!=0)
			return;

		//单字符与数字相差的是 48 		
		if(cnt==len){
			flag=0;
			rst =x;
			return;
		}
		k=next_k;	
	}

}

int main()
{
	freopen("runround.in","r",stdin);
	freopen("runround.out","w",stdout);
	cin>>M;
	int i;

	for(i=M+1;flag;i++){
		memset(vis,0,10*4);
		isrunaround(i);
		
	}
	cout<<rst<<endl;
	return 0;
}
