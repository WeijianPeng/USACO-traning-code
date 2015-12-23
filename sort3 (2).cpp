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
			for(j=i+1;j<N;j++){ //计算有长度为2的环，交换次数加1         
				if(seq2[j]==seq1[i]&&seq2[j]!=seq1[j]&&seq2[i]==seq1[j]){//在后面的所有数中找一个与其交换（两个组合，组成的一个环），前提是seq[2]位置的数本来就是需要交换的,并交换seq2[j].
					{cnt=cnt+1;temp=seq2[i];seq2[i]=seq2[j];seq2[j]=temp;break;}//seq2[j]=-1;
				}
			}
		}
	}

	for (i=0;i<N;i++)
	{
		if(seq2[i]!=seq1[i]){
    	for(j=i+1;j<N;j++){ //计算有长度为3的环，拆开两步交换（长度为3的环拆分成两个长度为2的环）           
	    	if(seq2[j]==seq1[i]&&seq2[j]!=seq1[j]){//在后面的所有数中找一个与其交换（两个组合，组成的一个环），前提是seq[2]位置的数本来就是需要交换的,并交换seq2[j].
				{cnt=cnt+1;temp=seq2[i];seq2[i]=seq2[j];seq2[j]=temp;break;}//seq2[j]=-1;
			}
		}
		}
	}
	cout<<cnt<<endl;

	return 0;
}