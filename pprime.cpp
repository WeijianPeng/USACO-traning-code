/*ID:pen_wan1
LANG:C++
TASK:pprime
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>

using namespace std;

int palindrome[1000000];

int isprime(int x){
	int i,temp=sqrt(x);
	for (i=2;i<=temp;i++)
	{   if(x%i==0)
			return 0;
	}
	return 1;
}

int main(){
	
	freopen("pprime.in","r",stdin);
	freopen("pprime.out","w",stdout);

	int a,b;
	scanf("%d %d",&a,&b);
  
	int i=0,d1,d2,d3,d4;

/* generate one digit palindrome: */
for (d1 = 2; d1 <= 9; d1+=1)
    palindrome[i++] = d1;

/* generate two digiit palindrome: */
	palindrome[i++] = 11;

/* generate three digiit palindrome: */
for (d1 = 1; d1 <= 9; d1+=2)
   for (d2 = 0; d2 <= 9; d2++) {
	   palindrome[i++] = 100*d1 +10*d2+ d1;
   }

/* generate five digit palindrome: */
for (d1 = 1; d1 <= 9; d1+=2) { 	/* only odd; evens aren't so prime */
    for (d2 = 0; d2 <= 9; d2++) {
        for (d3 = 0; d3 <= 9; d3++) {
			palindrome[i++] = 10000*d1 + 1000*d2 +100*d3 + 10*d2 + d1;	
		}
    }
}

/* generate seven digit palindrome: */
for (d1 = 1; d1 <= 9; d1+=2) { 	/* only odd; evens aren't so prime */
    for (d2 = 0; d2 <= 9; d2++) {
        for (d3 = 0; d3 <= 9; d3++) {
			for (d4 = 0; d4 <= 9; d4++){
				palindrome[i++] = 1000000*d1+100000*d2 + 10000*d3 + 1000*d4 + 100*d3+ 10*d2 + d1;
			}
		}
    }
}

int len,temp;
len=i-1;
for(i=0;i<len&&palindrome[i]<=b;i++){
	temp=palindrome[i];
			if (isprime(palindrome[i]) && palindrome[i]>=a){
				cout<<palindrome[i]<<endl;
			}		
	}
	return 0;
  }