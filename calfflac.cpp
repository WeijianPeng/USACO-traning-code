/*
ID:pen_wan1
LANG:C
TASK:calfflac
*/

//也可以用一个数组，标记所有字母位置
//nalpha>=2   errore
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define max 20000
char s[max];
int len=0,nend=1,nstart=1;


char * salph(char * p,int drection)
{
	if(p==&s[0]) {nstart=0;return p;}//
	if(p==&s[len-2]){nend=0;return p;}
	if (isalpha(*p))     //len1==0||
	{	
		return p;}
	else
	{
		salph(p+drection,drection);}
}


int main()
{
	freopen("calfflac.in", "r",stdin);
	freopen("calfflac.out","w",stdout);
	int i=0,j,mcount=1,count,st;
	char *p,*q,*p1,*q1;
	/*while (fin=='\n')
	{
		getchar();
	}*/
	while(scanf("%c",&s[i++])!=EOF);

	len=strlen(s);
	p=&s[0];//q=&s[len-2]
	p=salph(p,+1);

	st=p-&s[0];

	for (i=st;nend;i++)
	{
		nstart=1;count=0;
		p=&s[i],q=&s[i+1];
		p=salph(p,+1);
	    if(i==st) 
			p1=p;
	    q=salph(p+1,+1);
		if(i-st<1&&!isalpha(*q))
			q1=p;



		for (j=st;j==st||nend; j++)//(j<len1)&&
		{
			if(*p==*q||*p==*q+32||*p==*q-32){
                count=count+2;
				if(count==1919)
					count=1919;

			//	if(count==2) {}
				if(i-st>0&&nstart)
				{ p--;q++; }
				
			}
			else{
				if(j==st){
					count=1;//p1=p;q1=p;
					if(i-st>0) p--;}//len2-1
				else	break;		
			}
			if(count>mcount){
				mcount=count;
				if(i-st>0){      
					p1=p+1,q1=q-1;}	
			}
			if(!nstart) {
				p1=p;q1=q;break;}
			p=salph(p,-1);
			q=salph(q,+1);
			
		}
	}

	printf("%d\n",mcount);
	while(p1!=q1+1){
	//	if (*p1!='\n')
			printf("%c",*p1);
		p1++;
	}
	printf("\n");
	
	return (0);
}
