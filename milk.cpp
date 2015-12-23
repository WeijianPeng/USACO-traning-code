/*
ID:pen_wan1
LANG:C
TASK:milk
*/


#include<stdio.h>
#include<stdlib.h>
//#include <algorithm> 

typedef struct
{
	int p,a;
}Farmer;
Farmer farmer[5000];

int
cmp(const void *x, const void *y)
{
	Farmer *a, *b;
	
	a = (Farmer *)x;
	b = (Farmer *)y;
	
	if(a->p > b->p)//Farmer结构成员
		return 1;
	if(a->p < b->p)
		return -1;
	return 0;
}

int main()
{
	freopen("milk.in","r",stdin);
	freopen("milk.out","w",stdout);
	
	int N,M,i,s,m=0;//(0 <= N <= 2,000,000) , (0 <= M <= 5,000)
	
	scanf("%d %d",&N,&M);
	for(i=0;i<M;i++)
	{
		scanf("%d %d",&(farmer[i].p),&(farmer[i].a));
	}
    
	//int n[5000];
	//sort()



	qsort(farmer, M, sizeof(farmer[0]), cmp);

    
   for(i=0,s=N;s!=0;i++ )
   {
	   if(s>farmer[i].a){
		 s=s-farmer[i].a;
		 m+=farmer[i].p*farmer[i].a;
		}
	   else{
		  m+=s*farmer[i].p;
		  s=0;
	   }
   }
   printf("%d\n",m);

	return(0);
}