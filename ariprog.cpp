/*
ID:pen_wan1
LANG:C++
TASK:ariprog
*/
#include <iostream>
#include <stdio.h>
#include<algorithm>
#include<assert.h>


using namespace std;
typedef struct  
{ int a;
  int b;
}ariprog;

ariprog	Ariprog[10000];

int bsquare[130000+10],z=0;

// int check(int c,int M)
// {   
// 	for (;z<(M+1)*M&&c>=bsquare[z];z++)//
// 	{
// 		if(c==bsquare[z]) return 1;
// 	}
// 	return 0;
// 	
// }

int main(){
// freopen("ariprog.in","r",stdin);
// freopen("ariprog.out","w",stdout);
	FILE *fin,*fout ;
	fin=fopen("ariprog.in","r");
	fout=fopen("ariprog.out","w");
	assert(fin!=NULL&&fout!=NULL);


 int N,M;
 int a,b,c,ok;
 int i,j;
 int x,y;
 int id=0,k=0;
 fscanf(fin,"%d %d",&N,&M);

for (i=0;i<=M;i++)
  for (j=i;j<=M;j++)
  { bsquare[i*i+j*j]=1;id++;}

 
//  sort(bsquare,bsquare+id-1);
// 
// if(bsquare[y]==bsquare[y+1]) continue;

int temp=2*M*M;
for (x=1;x<=temp/(N-1);x++){//b<=temp&&
	  b=x;
	for (y=0;y<temp&&(y<=temp-x*(N-1));y++)//&&
	{   
		
		if(bsquare[y])  a=y;
		else continue;
	    /*y?z=0:z=y-1	;*/
		for (i=0;i<N;i++)//
		{   c=a+i*b;
	     	ok=(bsquare[c]?1:0);
	    	if (!ok)
			break;
		}
	   if (ok)
	   { Ariprog[k].a=a;Ariprog[k++].b=b;}
	}
}

	for ( i=0;i<k;i++)
	{
		fprintf(fout,"%d %d\n",Ariprog[i].a,Ariprog[i].b);
	}
	if(k==0)
     fprintf(fout,"NONE\n");
 return 0;

}