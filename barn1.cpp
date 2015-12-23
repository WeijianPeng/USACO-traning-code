/*ID:pen_wan1
LANG:C
TASK:barn1
*/
#include<stdio.h>
#include<stdlib.h>

#define max 200

typedef struct
{ 
	int start,end,interval;
} Interval;

Interval in[max];
	
int cmp(const void *va,const void *vb)
{
	return ((Interval *)vb)->interval - ((Interval *)va)->interval;//large to small  
	/*Interval *a, *b;//equal to return ((Interval *)va)->interval - ((Interval *)vb)->interval;
	
	a = (Interval *)va;
	b = (Interval *)vb;
	
	if(a->interval > b->interval)//Farmer结构成员
		return 1;
	if(a->interval < b->interval)
		return -1;
	return 0;*/
}
int cmp1(const void *va,const void *vb)
{
	return ((Interval *)va)->start - ((Interval *)vb)->start;
}
int main()
{
	freopen("barn1.in","r",stdin);
	freopen("barn1.out","w",stdout);

	int mboard,sstall,ccows,i,start,end;        //stall_num[200] M (1 <= M <= 50) (1 <= S <= 200) (1 <= C <= S) (1 <= stall_number <= S), 
	
	scanf("%d %d %d",&mboard,&sstall,&ccows);
	for (i=0;i<ccows;i++)
	{
		scanf("%d",&in[i].start);
	}
	
	qsort(in,ccows,sizeof(in[0]),cmp1);
	start=in[0].start;
	end=in[ccows-1].start;
	for (i=0;i<ccows-1;i++){
			in[i].end=in[i+1].start;
			in[i].interval=in[i].end-in[i].start-1;
	}
	qsort(in,ccows-1,sizeof(in[0]),cmp);

	int sinterval=0;
	for(i=0;i<mboard-1;i++){
		sinterval+=in[i].interval;
	}

   printf("%d\n",end-sinterval-start+1);



	return(0);
}