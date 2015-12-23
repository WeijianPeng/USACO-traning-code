/*
ID:pen_wan1
LANG:C++
TASK:fracdec
*/

//只有当出现了曾经出现过的余数时，小数部分才会出现重复
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int vis[100000],id[100000];
//vis表示余数0-99999是否出现，id表示对应余数出现的位置
int main()
{
    char itg[6];  //整数部分
    string dec,cycle,rst;//，小数非循环部分，循环体部分,最终结果
    int flag=1;//结束标志

    freopen("fracdec.in","r",stdin);
    freopen("fracdec.out","w",stdout);
    int N,D;  // fraction of the form N/D
    cin>>N>>D;
    dec=".";
    sprintf(itg,"%d",N/D);
    //itoa(N/D,itg,10);//convert int to string;//整数部分
    //标记余数，知道找到重复的余数或余数为0
    for(int i=1;flag;i++){
        N=N%D;
        char t1[2];
        //itoa(N/D,t2,10);//convert int to string 某些库不支持
        sprintf(t1,"%d",N*10/D);//t1为字符数组，不能为字符串类型
        dec=dec+t1;
        if(vis[N]==1){ //找到循环体
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
