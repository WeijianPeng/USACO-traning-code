/*
ID:pen_wan1
LANG:C++
TASK:subset
*/
#include<iostream>
#include<cstdio>

using namespace std;
//����ԭ������ѡ��n����Ʒ��ʹ��n����Ʒǡ�÷�������Ϊsum/2�ı����ķ�����������
int cnt;
int N;
int sum,i_sum;
int data[39+5];
unsigned int  F[39+5][(1+39)*39/(2*2)+5];


int main(){
	
	freopen("subset.in","r",stdin);
	freopen("subset.out","w",stdout);
	cin>>N;
	int i,v_sum;	
	
	sum=(1+N)*N/2;
	
    if (sum%2==1){
		cout<<0<<endl;
		return 0;
    }
	else{
		//F[0; 0...V ]= 0
		F[1][1]=1;
		F[1][0]=1;
		for(i=2;i<=N;i++){
			//F[i,j]��ʾȡǰi������ʹ������Ԫ������Ϊj�ķ�����
			for(v_sum=0;v_sum<i;v_sum++)
				F[i][v_sum]=F[i-1][v_sum];//�����ܺ�v_sumС��i,���ܽ���i���뼯��;F[i][v_sum]Ϊ���з�����

			for(v_sum=i;v_sum<=sum/2;v_sum++) {//�������пռ��Сi-N,Ŀǰi�������Եõ��ĺ�
				F[i][v_sum]=F[i-1][v_sum]+F[i-1][v_sum-i];
				
				}
		}
		
	cout<<F[N][sum/2]/2<<endl;
	}
		return 0;
	}