/*
ID:pen_wang1
LANG:C
TASK:transform
*/
/*
#1: 90 Degree Rotation: The pattern was rotated clockwise 90 degrees. 
#2: 180 Degree Rotation: The pattern was rotated clockwise 180 degrees. 
#3: 270 Degree Rotation: The pattern was rotated clockwise 270 degrees. 
#4: Reflection: The pattern was reflected horizontally (turned into a mirror image of itself by reflecting around a vertical line in the middle of the image). 
#5: Combination: The pattern was reflected horizontally and then subjected to one of the rotations (#1-#3). 
#6: No Change: The original pattern was not changed.
#7: Invalid Transformation: The new pattern was not obtained by any of the above methods. */
#include<stdio.h>
#define MANN 10

void rot90(char a[][10],char b[][10],int n)//
{	int i;
	for (i=0;i<n*n;i++)
		b[i/n][i%n]=a[n-1-i%n][i/n];
}

void rot180(char a[][10],char b[][10],int n)//
{	int i;
	for (i=0;i<n*n;i++)
		b[0+i/n][i%n]=a[n-1-i/n][n-i%n-1];
}

void rot270(char a[][10],char b[][10],int n)//
{	int i;
	for (i=0;i<n*n;i++)
		b[i/n][i%n]=a[i%n][n-i/n-1];
}

void reflect(char a[][10],char b[][10],int n)//
{	int i;
	for (i=0;i<n*n;i++)
		b[0+i/n][i%n]=a[(0+i)/n][n-i%n-1];
}

int nochange(char a[][10],char b[][10],int n)//
{	int i;
	for (i=0;i<n*n;i++)
		if(a[i/n][i%n]!=b[i/n][i%n]) return 0;
		return 1;
}
char pattern0[MANN][MANN],pattern1[MANN][MANN],tpattern2[MANN][MANN],tpattern3[MANN][MANN];

int main()
{

	freopen("transform.in","r",stdin);
	freopen("transform.out","w",stdout);
    int n,i,flag=1;
	scanf("%d",&n);
	getchar();
	for (i=0;i<n*n;i++){
		scanf("%c",pattern0[0+i/n]+i%n);
		if(i%n==n-1) getchar();
	}
	for (i=0;i<n*n;i++){
		scanf("%c",pattern1[0+i/n]+i%n);
		if(i%n==n-1) getchar();
	}

	rot90(pattern0,tpattern2,n);
	if(nochange(pattern1,tpattern2,n)){
		printf("1\n");flag=0;}
	
	rot180(pattern0,tpattern2,n);
	if(flag&&nochange(pattern1,tpattern2,n)){
		printf("2\n");flag=0;}

	rot270(pattern0,tpattern2,n);
	if(flag&&nochange(pattern1,tpattern2,n)){
		printf("3\n");flag=0;}

	reflect(pattern0,tpattern2,n);
	if(flag&&nochange(pattern1,tpattern2,n)){
		printf("4\n");flag=0;}

	if(flag){
		for (i=0;i<1;i++)
	   {
		reflect(pattern0,tpattern2,n);
		rot90(tpattern2,tpattern3,n);
		if(nochange(pattern1,tpattern3,n)){
			printf("5\n");break;}
		reflect(pattern0,tpattern2,n);rot180(tpattern2,tpattern3,n);
		if(nochange(pattern1,tpattern3,n)){
			printf("5\n");break;}
		reflect(pattern0,tpattern2,n);rot180(tpattern2,tpattern3,n);
		if(nochange(pattern1,tpattern3,n)){
			printf("5\n");break;}
	   }
	}
	flag=(i==1?1:0);
	   
	if(flag&&nochange(pattern1,pattern0,n)){
		printf("6\n");flag=0;}
	if(flag)
	printf ("7\n");
	return 0;
}
