/*
ID:pen_wan1
LANG:C
TASK:crypt1
*/

#include <stdio.h>
#include <string.h>

int three[1005],two[205],n,d[11];



int isin(int x)
{
	int i,j,di,len;char s[6];
	sprintf(s,"%d",x);
	len=strlen(s);
	for(i=0;i<len;i++)
	{
	  di=x%10;
	  for(j=0;j<n;j++){
		  if(di==d[j]) break;
	  }
	 if(j==n) return(0);
	 if(x/10==0) return(1);
	  x=x/10;
	}
}

int cmp(const void *va, const void *vb)
{
	return(*(int *)va-*(int *)vb);
}


int main()
{
	//freopen("crypt1.in","r",stdin);
	//freopen("crypt1.out","w",stdout);
	FILE *fin,*fout;
	fin=fopen("crypt1.in","r");
	fout=fopen("crypt1.out","w");

	int i,j,k,x,y,d1=0,d2=0,count=0,temp1,temp2,temp3;

	fscanf(fin,"%d",&n);
	for(i=0;i<n;i++)
		fscanf(fin,"%d",&d[i]);

	for (i=0;i<n;i++){
		for(j=0;j<n;j++){
			two[d1]=d[i]*10+d[j];
			for(k=0;k<n;k++){
				three[d2]=d[i]*100+d[j]*10+d[k];
				d2++;
			}
			d1++;
		}
	}

	for(x=0;x<d2;x++)
	{
		for(y=0;y<d1;y++){
			temp1=three[x]*two[y];
	        //if(999<temp1&&temp1<10000) break;
			if(isin(temp1)&&999<temp1&&temp1<10000){
				temp2=three[x]*(two[y]%10);
				temp3=three[x]*(two[y]/10%10);
				if(99<temp2&&temp2<1000&&99<temp3&&temp3<1000){
					if(isin(temp2)&&isin(temp3)){
						count++;//printf("%d %d\n",three[x],two[y]);
					}
				}
			}
		}
	}	
	
	//printf("%d\n",count);
	fprintf(fout,"%d\n",count);
	fclose(fin);
	fclose(fout);
	return(0);

}