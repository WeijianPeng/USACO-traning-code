/*
ID:pen_wan1
LANG:C
TASK:dualpal
*/

#include<stdio.h>
#include<string.h>

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

int ispal(char t[])
{
	int i,len;
	len=strlen(t);
	for(i=0;i<len/2;i++){
		if(t[i]!=t[len-1-i]) return(0);
	}
	return(1);
}


int main()
{
	freopen("dualpal.in","r",stdin);
	freopen("dualpal.out","w",stdout);
	int N,S,i=0,j,k,npal;
	char ncb[15];
	scanf("%d %d",&N,&S);//N (1 <= N <= 15) S (0 < S < 10000)
		for (j=S+1;i<N;j++)
		{
			npal=0;
			for(k=2;k<11;k++){
				trans(k,j,ncb);
				npal+=ispal(ncb);
				if(npal>=2){
					printf("%d\n",j);
					i++;break;
				}	
			}	
		}



	return(0);
}