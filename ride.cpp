/*
ID: pen_wan1
LANG: C
TASK: ride
*/
#include <stdio.h>
#include<string.h>
int main ()
{
	char s1[7],s2[7];
	int i,r1,r2;
 	freopen("ride.in","r",stdin);
	freopen("ride.out","w",stdout);
	while(scanf("%s %s",s1,s2)!=EOF)
    {
        r1=1;r2=1;
		for (i=0;i<strlen(s1);i++)
		{
			r1=r1*(s1[i]-64);
		}
		for (i=0;i<strlen(s2);i++)
		{
			r2=r2*(s2[i]-64);
		}
		if (r1%47==r2%47)
		{
			printf("GO\n");
		}
		else
		{
			printf("STAY\n");
		}
	}
	return(0);
}


????
