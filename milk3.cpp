/*
ID:pen_wan1
LANG:C++
TASK:milk3
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

int cot[25];
int min(int a,int b)
{
    return a>b?b:a;
}

int main()
{
    FILE *fin,*fout;
    fin=fopen("milk3.in","r");
    fout=fopen("milk3.out","w");
    int a,b,c;
    fscanf(fin,"%d %d %d",&a,&b,&c);

    int vis[25][25][25];// ״̬��־
    memset(vis,0,sizeof(vis));

    queue<int> q1,q2,q3;  //������3������
    vis[0][0][c]=1;

    memset(cot,0,sizeof(cot));

    q1.push(0);q2.push(0);q3.push(c);
    int t1,t2,t3,pour,aa,bb,cc;

    while(!q1.empty())//����1��Ϊ��ʱ
    {
        t1=q1.front();t2=q2.front();t3=q3.front();

        q1.pop();q2.pop();q3.pop();

        if(t1==0&&!cot[t3]) //AΪ�գ���C���µ�ţ����
			cot[t3]=1;
        //��A����B
        if(t1!=0&&t2!=b)//A��Ϊ�գ�B������---�ܵ�
        {
            pour=min(b-t2,t1);
            aa=t1-pour;
            bb=t2+pour;
            cc=t3;
            if(!vis[aa][bb][cc])
            {q1.push(aa);q2.push(bb);q3.push(cc);vis[aa][bb][cc]=1;}
        }
        //��A����C
        if(t1!=0&&t3!=c)
        {
            pour=min(c-t3,t1);
            aa=t1-pour;
            bb=t2;
            cc=t3+pour;
            if(!vis[aa][bb][cc])
            {q1.push(aa);q2.push(bb);q3.push(cc);vis[aa][bb][cc]=1;}
		}
        //��B����A
        if(t2!=0&&t1!=a)
        {
            pour=min(a-t1,t2);
            aa=t1+pour;
            bb=t2-pour;
            cc=t3;
            if(!vis[aa][bb][cc])
            {q1.push(aa);q2.push(bb);q3.push(cc);vis[aa][bb][cc]=1;}
        }
        //��B����C
        if(t2!=0&&t3!=c)
        {
            pour=min(t2,c-t3);
            aa=t1;
            bb=t2-pour;
            cc=t3+pour;
            if(!vis[aa][bb][cc])
            {q1.push(aa);q2.push(bb);q3.push(cc);vis[aa][bb][cc]=1;}
        }
        //��C����A
        if(t3!=0&&t1!=a)
        {
            pour=min(t3,a-t1);
            aa=t1+pour;
            bb=t2;
            cc=t3-pour;
            if(!vis[aa][bb][cc])
            {q1.push(aa);q2.push(bb);q3.push(cc);vis[aa][bb][cc]=1;}
        }
        //��C����B
        if(t3!=0&&t2!=b)
        {
            pour=min(t3,b-t2);
            aa=t1;
            bb=t2+pour;
            cc=t3-pour;
            if(!vis[aa][bb][cc])
            {q1.push(aa);q2.push(bb);q3.push(cc);vis[aa][bb][cc]=1;}
        }
    }


	int flag=1;
    for(int i=0;i<21;i++)
    {
		if(cot[i]&&flag)
		{
			fprintf(fout,"%d",i);flag=0;
		}
		else if(cot[i])
			fprintf(fout," %d",i);
	}
    fprintf(fout,"\n");
    return 0;
}
































