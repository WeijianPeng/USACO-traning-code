/*
ID:pen_wang1
LANG:C
TASK:namenum
*/


#include<stdio.h>
#include<string.h>

char s[5001][13];
char st[5001][13];

int main()
{
	freopen("dict.txt","r",stdin);
	int i=0,j=0,flag=0;
	char c[13];
	while(scanf("%s",s[i++])!=EOF)
	{
		char *s0=s[i-1],(*c)=st[i-1];
        for (j=0;j<strlen(s[i-1]);j++)
        { 
			
				if('A'<=*(s0+j)&&*(s0+j)<='C')
					c[j]='2';
				if('D'<=*(s0+j)&&*(s0+j)<='F')
					c[j]='3';
				if('G'<=*(s0+j)&&*(s0+j)<='I')
					c[j]='4';
				if('J'<=*(s0+j)&&*(s0+j)<='L')
					c[j]='5';
				if('M'<=*(s0+j)&&*(s0+j)<='O')
					c[j]='6';
				if((*(s0+j))=='P'||(*(s0+j))=='R'||(*(s0+j))=='S')
					c[j]='7';
				if('T'<=s0[j]&&s0[j]<='V')
					c[j]='8';
				if('W'<=s0[j]&&s0[j]<='Y')
					c[j]='9';
				if('Q'==s0[j]||s0[j]=='Z')
					c[j]='?';
		}
		c[j]='\0';
		//sscanf(s,"%d",&st[j]);
   }

	freopen("namenum.in","r",stdin);
	freopen("namenum.out","w",stdout);
	char  n[13];
	scanf("%s",n);//?
	
	for(j=0;j<i-1;j++){
		if (!strcmp(n,st[j])) {
			printf("%s\n",s[j]);flag=1;}
	}
	
	if(!flag)
 		printf("NONE\n");



	return(0);
}