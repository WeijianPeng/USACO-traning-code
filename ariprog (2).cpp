/*
ID:pen_wan1
LANG:C++
TASK:ariprog
*/
#include <iostream>
#include <stdio.h>
#include <time.h>
#include<algorithm>
#include<assert.h>

using namespace std;
typedef struct  
{ int a;
  int b;
}ariprog;

ariprog	Ariprog[10000];

int bsquaretemp[130000+10],
	bsquare[130000+10],z=0;

int cmp(int i,int j)
{  return  Ariprog[i].b<Ariprog[j].b;
}
int main(){
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
  { bsquaretemp[i*i+j*j]=1;}

for (i=0;i<=2*M*M;i++)
  { if(bsquaretemp[i]==1)
      bsquare[id++]=i;}
  
 id--;

int temp;

 for (x=0;x<=id;x++){
	 a=bsquare[x];
	 for (y=x+1;y<=id;y++){
		b=bsquare[y]; b=b-a;
		if(a+(N-1)*b<=bsquare[id]) 
     	{
		
// 		if(bsquare[y])  {a=y;id--;}
// 		else continue;
		
		for (i=0;i<N;i++)//
		{   c=a+i*b;
	     	ok=(bsquaretemp[c]?1:0);
	    	if (!ok)
			break;
		}
	   if (ok)	{ Ariprog[k].a=a;Ariprog[k++].b=b;}
		}
		else break;
	}
}

 int st[100];
 for (i=0;i<k;i++) st[i]=i; 
 
    sort(st,st+k,cmp);
	for ( i=0;i<k;i++)
	{
		fprintf(fout,"%d %d\n",Ariprog[st[i]].a,Ariprog[st[i]].b);
	}
	if(k==0)
     fprintf(fout,"NONE\n");

	//printf("Time used=%.2lf\n",(double)clock()/CLOCKS_PER_SEC);
 return 0;

}