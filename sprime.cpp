/*ID:pen_wan1
LANG:C
TASK:sprime
*/
#include <stdio.h>
#include <math.h>
// #include <iostream>
// #include <string>
// using namespace std;

int num1[4]={2,3,5,7};
int num2[4]={1,3,7,9};

int isprime(int x){
	int i,temp=sqrt(x);
	if (x==2)
		return 1;
	for (i=2;i<=temp;i++)
	{   if(x%i==0)
		return 0;
	}
	return 1;
}

void dfs(int p,int n,int N){
    int i;
	for (i=0;i<4&&n<N;i++){ 
		p=p*10+num2[i];

		if (isprime(p)){
			n=n+1;
			if(n==N) {
				printf("%d\n",p);}

            if (n<N)
				 dfs(p,n,N);

			n=n-1;p=p/10;
			continue;
		}

		else {
			p=p/10;
			continue;}	
	}	
}

int main(){
	int N,p;

	freopen("sprime.in","r",stdin);
	freopen("sprime.out","w",stdout);
    scanf("%d",&N);
	int i;
	for (i=0;i<4;i++){	
		p=num1[i];
	    if (N==1)
			{printf("%d\n",num1[i]);}
        else
			dfs(p,0,N-1);   
	}	
	return 0;
}