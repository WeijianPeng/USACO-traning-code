/*
ID:pen_wan1
LANG:C++
TASK:sort3
*/
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int N;
int seq1[1000+10],seq2[1000+10];//1000+1000+
int cnt=0;

int main()
{
	freopen("sort3.in" , "r",stdin);
	freopen("sort3.out", "w",stdout);


	cin>>N;
	int i,j,temp;
	for (i=0;i<N;i++)
	{
		cin>>seq1[i];seq2[i]=seq1[i];
	}

	sort(seq1,seq1+N);

	for (i=0;i<N;i++)
	{
		if(seq2[i]!=seq1[i]){//&&seq2[i]!=-1    
			for(j=i+1;j<N;j++){ //�����г���Ϊ2�Ļ�������������1         
				if(seq2[j]==seq1[i]&&seq2[j]!=seq1[j]&&seq2[i]==seq1[j]){//�ں��������������һ�����佻����������ϣ���ɵ�һ��������ǰ����seq[2]λ�õ�������������Ҫ������,������seq2[j].
					{cnt=cnt+1;temp=seq2[i];seq2[i]=seq2[j];seq2[j]=temp;break;}//seq2[j]=-1;
				}
			}
		}
	}

	for (i=0;i<N;i++)
	{
		if(seq2[i]!=seq1[i]){
    	for(j=i+1;j<N;j++){ //�����г���Ϊ3�Ļ�������������������Ϊ3�Ļ���ֳ���������Ϊ2�Ļ���           
	    	if(seq2[j]==seq1[i]&&seq2[j]!=seq1[j]){//�ں��������������һ�����佻����������ϣ���ɵ�һ��������ǰ����seq[2]λ�õ�������������Ҫ������,������seq2[j].
				{cnt=cnt+1;temp=seq2[i];seq2[i]=seq2[j];seq2[j]=temp;break;}//seq2[j]=-1;
			}
		}
		}
	}
	cout<<cnt<<endl;

	return 0;
}