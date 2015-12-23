/*
TASK:inflate
ID:pen_wan1
LANG:C++
*/

#include <iostream>
#include <cstdio>

using namespace std;
int mymax(int i,int j){
    if (i>j) return i;
    return j;
}

int M,N;//����ʱ�䣨�ȼ۱������������Ŀ������Ŀ
int W[10000+5],C[10000+5];//ÿ����Ŀ�ļ�ֵ�ͺ�ʱ
int F[10000+5];//�ڶʱ���ڣ���ȡ�õ����֣���ֵ��
int main()
{

    freopen("inflate.in","r",stdin);
    freopen("inflate.out","w",stdout);

    cin>>M>>N;
    for(int i=1;i<=N;i++){
        cin>>W[i]>>C[i];
    }

//��ȫ�����������������ʡ�ռ䣩
    //��ʼ������Ϊ��ʱ�������M������װ����
    // F[0]=0;
    // for(int i=1;i<=M;i++){F[i]=-10000;}

    for(int i=1;i<=N;i++){
        for(int v=C[i];v<=M;v++)
            F[v]=mymax(F[v],F[v-C[i]]+W[i]);
    }
    cout<<F[M]<<endl;
    return 0;
}