/*
ID:pen_wan1
LANG:C++
TASK:fracdec
*/

//ֻ�е��������������ֹ�������ʱ��С�����ֲŻ�����ظ�
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int vis[100000],id[100000];
//vis��ʾ����0-99999�Ƿ���֣�id��ʾ��Ӧ�������ֵ�λ��
int main()
{
    char itg[6];  //��������
    string dec,cycle,rst;//��С����ѭ�����֣�ѭ���岿��,���ս��
    int flag=1;//������־

    freopen("fracdec.in","r",stdin);
    freopen("fracdec.out","w",stdout);
    int N,D;  // fraction of the form N/D
    cin>>N>>D;
    dec=".";
    sprintf(itg,"%d",N/D);
    //itoa(N/D,itg,10);//convert int to string;//��������
    //���������֪���ҵ��ظ�������������Ϊ0
    for(int i=1;flag;i++){
        N=N%D;
        char t1[2];
        //itoa(N/D,t2,10);//convert int to string ĳЩ�ⲻ֧��
        sprintf(t1,"%d",N*10/D);//t1Ϊ�ַ����飬����Ϊ�ַ�������
        dec=dec+t1;
        if(vis[N]==1){ //�ҵ�ѭ����
           int st=id[N];
           int len=i-st;
            cycle=dec.substr(st,len);dec=dec.substr(0,st);flag=0;break;
            }
        vis[N]=1;
        id[N]=i;
        N=N*10;
        if(N%D==0){break;}
    }
    string ss1,ss2;
    if(flag==0) {ss1="(";ss2=")";}
    rst=itg+dec+ss1+cycle+ss2;
    for(unsigned int i=0;i<=rst.length()/76;i++)
        cout<<rst.substr(76*i,76)<<endl;
    return 0;
}
