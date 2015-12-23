/*
ID:pen_wan1
LANG:C++
TASK:hamming
*/

#include<iostream>
#include<cstdio>

using namespace std;

int N,B,D;
int num[256+10];

int cout_num(int a){//����Bλ����0�ľ��룬��Bλ����1�ĸ���
    int i,cnt=0;

	for (i=0;i<B;i++)
	{  cnt=cnt+(a&1);
	   a=a>>1;
	}
	return cnt;

}
int isok(int x,int c,int d){
	int i,temp;
	for (i=0;i<c;i++)
	{
		temp=x^num[i];//�����������ͨ������Bλ��x��1�ĸ���
		if (cout_num(temp)<d)
		  return 0;
	}
    return 1;
}


int main()
{

	freopen("hamming.in","r",stdin);
	freopen("hamming.out","w",stdout);

	scanf("%d%d%d",&N,&B,&D);
    
     num[0]=0; //0�Ǳ�Ȼ����ֵġ�
	int vis=0;
	int i,j;
	for (i=1;i<=256;i++)
	{
		if(isok (i,vis+1,D)) 
			num[++vis]=i;

	}
	i=0;
	for(i=0;i<N;i++){
		printf("%d",num[i]);
		if ((i+1)%10==0 || i==N-1) 
			cout<<endl;
		else if (i<N-1)
			printf(" ");//cout<<' ';��֪��ô��cout����ո�
			
	}
	return 0;
}