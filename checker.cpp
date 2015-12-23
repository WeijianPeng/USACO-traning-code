/*
ID:pen_wan1
LANG:C
TASK:checker
*/

#include <stdio.h>
#include <string.h>
int N;
int c[14];
int sum;
int vis[3][26];


void placequeen(int row){ 
	int i;

	if (row==N){
		sum++;	
		if (sum<4){
			for (i=0;i<N;i++)
			{	printf("%d",c[i]+1);		
				if(i!=N-1) printf(" ");}
			printf("\n");
		}	
		return;
	}

	int col;
	for (col=0;col<N;col++)  //new (row,col) try 0~N column
	{  
	
		if (!vis[0][col] && !vis[1][col+row] && !vis[2][row-col+N])
		{  
			c[row]=col;

			vis[0][col]=1; vis[1][col+row]=1; vis[2][row-col+N]=1;

			placequeen(row+1);

			vis[0][col]=0; vis[1][col+row]=0; vis[2][row-col+N]=0;
		}
	}
}

int  main(){
	
	freopen("checker.in","r",stdin);
	freopen("checker.out","w",stdout);
	scanf("%d",&N);
	sum=0;

	memset(vis,0,sizeof(vis)); //[0][0])*42
	placequeen(0);
		
	printf("%d\n",sum);
	return 0;
}