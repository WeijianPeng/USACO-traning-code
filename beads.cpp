/*
ID:pen_wan1
LANG:C
TASK:beads
*/
#include<stdio.h>
#include<string.h>
#define MAX -0x80000000
int main()
{
	freopen("beads.in","r",stdin);
	freopen("beads.out","w",stdout);
	/*FILE *fin,*fout;
	fin=fopen("beads.txt","r");
	fout=fopen("beads.out","w");*/

	int n,i,j,k,temp,max=MAX,flag1,flag2,flag3;
	char s[351],c,d;
	//memset(s,0,sizeof(s));
    
	//getchar();
	//scanf("%d",&n);
	//getchar();
	//scanf("%s",s);
	//getchar();
	scanf("%d %s",&n,s);
	//fscanf(fin,"%d%*c",&n);
	//fscanf(fin,"%s",s);
	//fscanf(fin,"")
	for(i=0;i<n;i++){
			temp=0;flag1=0;flag2=0;flag3=0;
			for (j=i,k=0;k<n;j=((++j)%n),k++){
				if (((s[j]=='w')||(s[j]==c)||flag2==0)&&flag1==0){
					if((s[j]=='r'||s[j]=='b')&&flag2==0){
						c=s[j];flag2=1;}
					temp+=1;
				}
				else if(flag3==0||s[j]=='w'||s[j]==d){
					if(flag3==0){
						d=s[j];flag3=1;
					}
					temp+=1;flag1=1;
				}	
				else break;
			}
			if(temp>max)
				max=temp;
	}
	printf("%d\n",max);
	return(0);
}