/*
ID:pen_wan1
LANG:C++
TASK:combo
*/

# include<iostream>
# include<cstdio>
# include<string.h>
using namespace std;


int vis[12000+5];
int main(){
	freopen("combo.in","r",stdin);
	freopen("combo.out","w",stdout);

	int N,combo1[3],combo2[3],num1,num2,cnt=0;
	int i,j,k;
	memset(vis,0,sizeof(vis));

	cin>>N;
	for (i=0;i<3;i++)
		cin>>combo1[i];
	
	for (i=0;i<3;i++)
		cin>>combo2[i];
	

 	for (i=-2;i<3;i++)
 		for (j=-2;j<3;j++)		
 			for (k=-2;k<3;k++){
 				num1=((combo1[0]+i+N)%N)*100+((combo1[1]+j+N)%N)*10+((combo1[2]+k+N)%N);
				if (!vis[num1]) {cnt++;vis[num1]=1;}

 				num2=((combo2[0]+i+N)%N)*100+((combo2[1]+j+N)%N)*10+((combo2[2]+k+N)%N);    
				if (!vis[num2])  {cnt++;vis[num2]=1;}
 			}
			cout<<cnt<<endl;
				
	return 0;

}
