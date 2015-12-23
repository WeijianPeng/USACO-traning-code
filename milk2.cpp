/*
ID:pen_wang1
LANG:C++
TASK:milk2
*/ 
#include <iostream>
#include <algorithm> 
#include<cstdio>
using namespace std;

typedef struct  
{
	int sta;
	int end;
}farmer;

farmer farmers[5005], farmers1[5005];

/*int cmp(const void *a, const void *b)
{
    return (((farmer*)a).sta - ((farmer*)b).sta);
}*/

struct cmp
{
	bool operator () ( const farmer &a, const farmer &b ) const 
	{
		return a.sta < b.sta;
	}
};

/*int cmp(const farmer * i,const farmer * j){
	return((*i).sta<((*j).sta));
}*/
farmer *p=farmers;
farmer *q=farmers1;
//farmers1[0].sta=0,farmers1[0].end=0;

int main()
{
	freopen("milk2.in","r",stdin);
	freopen("milk2.out","w",stdout);
	int n,continues=0,idle=0,count=1,temp1,temp2,i,j;
	scanf("%d",&n);
	for ( i=0;i<n;i++,p++){
		scanf("%d%d",&(*p).sta,&(*p).end);
	}
    sort(farmers,farmers+n,cmp());

	p=farmers;
    (*q).sta=(*p).sta,(*q).end=(*p).end;
	for (i=1,p++;i<n;i++,p++){
		if (((*q).sta<=(*p).sta&&(*p).sta<=(*q).end)){
			if((*p).sta<=(*q).sta)
				(*q).sta=(*p).sta;
			if((*p).end>(*q).end)
				(*q).end=(*p).end;
		}
		else{
			(*++q).sta=(*p).sta;
			(*q).end=(*p).end;
			count++;
		}
	}
	for(i=0,j=1;i<count;i++,j++){
		temp1=farmers1[i].end-farmers1[i].sta;
		if(temp1>continues)
			continues=temp1;
		temp2=farmers1[j].sta-farmers1[j-1].end;
		if(temp2>idle)
			idle=temp2;
      
	}
	printf("%d %d\n",continues,idle);
	
	return (0);
}