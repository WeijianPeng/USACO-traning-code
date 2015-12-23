/*
ID:pen_wan1
LANG:C++
TASK:concom
*/
#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int N;
long long ctrlcp[100+5][100+5];
int vis[100+5][100+5];

void dfs(int i,int j){//��˾i�����˹�˾j��
        vis[i][j]=1;
        for(int k=0;k<100;k++){
            if(ctrlcp[j][k]>=50&&j!=k&&!vis[j][k])//(1,2,3)�ͣ�1,4,3��
            {dfs(j,k);}
        }

        for(int k=0;k<100;k++){
            ctrlcp[i][k]+=ctrlcp[j][k]%101;
            if(ctrlcp[i][k]>=50&&i!=k&&j!=k&&!vis[i][k]&&!vis[j][k]){dfs(i,k);}
        }

}


int main()
{
    freopen("concom.in","r",stdin);
    freopen("concom.out","w",stdout);
    cin>>N;
    for(int i=0;i<N;i++){
        int j,k;
        cin>>j>>k;
        cin>>ctrlcp[j-1][k-1];
    }

    for(int i=0;i<100;i++){
       for(int j=0;j<100;j++){
            if(ctrlcp[i][j]>=50&&j!=i&&!vis[i][j])
                {dfs(i,j);}
        }
    }

    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++)
            if (ctrlcp[i][j]>=50&&i!=j)
                cout <<i+1<<" "<<j+1<<endl;
    }

    return 0;
}







// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <assert.h>
 
// #define NCOM 101
 
// int owns[NCOM][NCOM];        /* [i,j]: iֱ�ӡ����ӵ����j�Ķ��ٹɷݣ� */
// int controls[NCOM][NCOM];    /* [i, j]: i�Ƿ����j�� */
 
// /* ������Ϣ������i������j */
// void
// addcontroller(int i, int j)
// {
    // int k;
 
    // if(controls[i][j])        /* ���ƹ�ϵ��֪ */
        // return;
 
    // controls[i][j] = 1;
 
    // /* ����i������j����jӵ�еĹɷݶ��ӵ�i�� */
	// for(k=0; k<NCOM; k++)
        // owns[i][k] += owns[j][k];
 
    // /* ��¼��i�Ŀ���������Ҳ������j */
	// for(k=0; k<NCOM; k++)
        // if(controls[k][i])
            // addcontroller(k, j);
 
    // /* �������i�����˸���Ĺ�˾�����¼ */
    // for(k=0; k<NCOM; k++)
        // if(owns[i][k] > 50)
            // addcontroller(i, k);
// }
 
// /* ������Ϣ��iӵ��j��p%�ɷ� */
// void
// addowner(int i, int j, int p)
// {
    // int k;
 
    // /* ��ÿ��i�Ŀ���������j��p%�ɷ� */
	// for(k=0; k<NCOM; k++)
        // if(controls[k][i])
            // owns[k][j] += p;
 
    // /* Ѱ��j���¿����� */
	// for(k=0; k<NCOM; k++)
        // if(owns[k][j] > 50)
            // addcontroller(k, j);
// }
 
// int
// main()
// {
    // FILE *fin, *fout;
    // int i, j, n, a, b, p;
 
    // fin = fopen("concom.in", "r");
    // fout = fopen("concom.out", "w");
    // assert(fin != NULL && fout != NULL);
 
    // for(i=0; i<NCOM; i++)
        // controls[i][i] = 1;
 
    // fscanf(fin, "%d", &n);
    // for(i=0; i<n; i++) {
        // fscanf(fin, "%d %d %d", &a, &b, &p);
        // addowner(a, b, p);
    // }
 
    // for(i=0; i<NCOM; i++)
    // for(j=0; j<NCOM; j++)
        // if(i != j && controls[i][j])
            // fprintf(fout, "%d %d\n", i, j);
    // return 0;
// }