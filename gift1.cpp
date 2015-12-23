/*
ID: pen_wan1
LANG: C
TASK: gift1
*/
#include<stdio.h>
#include<string.h>
int main()
{
	freopen("gift1.in","r",stdin);
	freopen("gift1.out","w",stdout);
	int np,gn,d_money,a_money,r_money;
	int i,j,k;
	char s1[15],s2[15];
	
	struct giver 
	{	
		char name[15];
		int money;//amount of money 
		//int n_g;//the number of people to whom the giver will give gifts
		//struct receiver receivers[10];
	}; 
	scanf("%d",&np);
	struct giver givers[13];
	struct giver *p;
	p=givers;
	for(i=0;i<np;i++,p++)
	{
		scanf("%s",(*p).name);
		givers[i].money=0;
	}
	for (i=0;i<np;i++)
	{   
		scanf("%s",s1);
		for (k=0;k<np;k++)
		{	
		if(strcmp(s1,givers[k].name)==0)
		{
		scanf("%d%d",&a_money,&gn);
		if(gn==0)
		{
			givers[k].money+=a_money;
			break;
		}
		d_money=a_money/gn;
        r_money=a_money-d_money*gn;
		givers[k].money+=r_money-a_money;
		for (j=0;j<gn;j++)
		{
			scanf("%s",s2);
			for (k=0;k<np;k++)
			{
				if(strcmp(s2,givers[k].name)==0)
				{
					givers[k].money+=d_money;
					break;
				}	
			}
		}
		break;
		}
	}
	}
	for (i=0;i<np;i++)
	{	
		printf("%s %d\n",givers[i].name,givers[i].money);
	}
	return(0);
}
