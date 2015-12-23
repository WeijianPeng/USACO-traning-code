/*
ID:pen_wan1
LANG:C++
TASK:castle
*/
#include<iostream>
#include<stdio.h>

using namespace std;


int M,N,c=0;
int data[60][60],wall[60][60][5],roomfill[60][60],vis[60][60];
int count[2500];

/*
1: wall to the west
2: wall to the north
4: wall to the east
8: wall to the south
*/
void search (int i,int j,int c){
	

// search west
	if(((data[i][j]&1)==0)&&(0==vis[i][j-1]))  {roomfill[i][j-1]=c;vis[i][j-1]=1; search(i,j-1,  c);}
//north
	if(((data[i][j]&2)==0)&&(0==vis[i-1][j]))  {roomfill[i-1][j]=c;vis[i-1][j]=1; search(i-1, j,c);}
//east
	if(((data[i][j]&4)==0)&&(0==vis[i][j+1]))  {roomfill[i][j+1]=c;vis[i][j+1]=1; search(i,j+1,  c);}
//cout<<(data[i][j]&4);
//south
	if(((data[i][j]&8)==0)&&(0==vis[i+1][j]))  {roomfill[i+1][j]=c;vis[i+1][j]=1; search(i+1,  j,c);}

	return ;
}

//////////////////////////////////////////////////////

int main(){
	freopen("castle.in","r",stdin);
	freopen("castle.out","w",stdout);
    
	scanf("%d %d",&N,&M);
	
	int i,j,k;
	for (i=0;i<M;i++)
		for (j=0;j<N;j++)
		{	cin>>data[i][j];
		}


	//floodfill 种子染色法

	for (i=0;i<M;i++)
		for (j=0;j<N;j++)
		{	if (0==vis[i][j]) { roomfill[i][j]=c; vis[i][j]=1; search(i,j,c++);}	
		}


	for (i=0;i<M;i++)
		for (j=0;j<N;j++)
		{	count[roomfill[i][j]]+=1;		
		}

    int maxsize=0;
	for (j=0;j<c;j++)
	{	if(count[j]>maxsize)
			maxsize=count[j];		
		}



	int rslt[2];
	char s;
	int maxarea=0;

	for (j=0;j<N;j++)
		for (i=M-1;i>-1;i--)
		{
			//search north wall
			if((i>0&&data[i][j]^2==1)&&(roomfill[i][j]!=roomfill[i-1][j])){
				if(count[roomfill[i][j]]+count[roomfill[i-1][j]]>maxarea)
				{	maxarea=count[roomfill[i][j]]+count[roomfill[i-1][j]];
					rslt[0]=i+1,rslt[1]=j+1;s='N';}
			}
			
			//search east wall
			if((j<N-1&&data[i][j]^4==1)&&(roomfill[i][j]!=roomfill[i][j+1])) {
				if(count[roomfill[i][j]]+count[roomfill[i][j+1]]>maxarea) 
				{	maxarea=count[roomfill[i][j]]+count[roomfill[i][j+1]];
				rslt[0]=i+1,rslt[1]=j+1;s='E';}
			}
		
		
	
		}

		cout<<c<<endl<<maxsize<<endl<<maxarea<<endl<<rslt[0]<<" "<<rslt[1]<<" "<<s<<endl;

		return 0;

	
}
