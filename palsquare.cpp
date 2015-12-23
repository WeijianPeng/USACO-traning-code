/*
ID:pen_wan1
LANG:C
TASK:palsquare
*/

#include<stdio.h>
#include<memory.h>
#include <string.h>

char n[9], nsq[17];
//memset(&n[0],'0',sizeof(n));
 

void trans(int b,int num,char bnum[])//base & number
{
	int len,r,i;//mod,remainder
	char temp;
	
	for(i=0;num!=0;i++)
	{
		r=num%b;
		if(r<10)
			bnum[i]=(char)(r+48);
		else
			bnum[i]=(char)(r+48+7);
		num=(num-r)/b;
		}
	bnum[i]='\0';
	//sprintf(s,"%d",num);
	len=strlen(bnum);
	//reverse
	for(i=0;i<len/2;i++){
		temp=bnum[i];
		bnum[i]=bnum[len-1-i];
		bnum[len-1-i]=temp;
	}
	

}

	//sprintf(bnum[m],"%d",r);      //transform int(n) to string(s);

int ispal(char t[])
{
	int i,len;
	len=strlen(t);
	for(i=0;i<len/2+1;i++){
		if(t[i]!=t[len-1-i]) return(0);
		}
	return(1);
}

int main()
{
	freopen("palsquare.in","r",stdin);
	freopen("palsquare.out","w",stdout);
	int nb,i,j,sq;
	scanf("%d",&nb);

    for (i=1;i<=300;i++)
    {
		sq=i*i;
		trans(nb,sq,nsq);
		if(ispal(nsq)) {
			trans (nb,i,n);
			printf("%s %s\n",n,nsq);
        }
    }

	return(0);
}