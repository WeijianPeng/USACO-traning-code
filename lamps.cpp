/*
ID:pen_wan1
LANG:C++
TASK:lamps
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <algorithm>

using namespace std;

int N,C;
vector<int> final_on,final_off;
string s1;
map<int,bool> mymap;//第一个为key,int类型，必须唯一。
int state6[16];//利用N个灯的周期性，只要考虑前6个灯即可；最多16种状态

int check(string s){
    for(int i=0;i<final_on.size();i++)
        {if(s[(final_on[i]-1)%6]=='0') return 0;}
    for( int i=0;i<final_off.size();i++)
        {if(s[(final_off[i]-1)%6]=='1')return 0;}
    return 1;
    }

int main()
{
    ifstream fin ("lamps.in");
    ofstream out("lamps.out");
    fin>>N;
    fin>>C;

    for(int i=0;fin>>i&&i!=-1;i++)
        final_on.push_back(i);
     for(int i=0;fin>>i&&i!=-1;i++)
        final_off.push_back(i);

//从开关的状态对应前6个灯的状态,最高位为第一个开关

//关于状态的记录，用一个int存储N个灯的前6位的状态就行了。
//状态的改变，通过开关，4种操作也很简单，用异或就可以搞定：
//操作1：异或(111111)=63 二进制数 等价于取反
//操作2：异或(010101)=21 改变偶数位
//操作3：异或(101010)=42 改变奇数位
//操作4：异或(100100)=36 改变1、4、7位
    int j=0;
    int c=C%2;
    int newstate;

    if(c==0){
        newstate=~0;
        if(mymap[newstate]==0)  {state6[j++]=newstate;mymap[newstate]=1;}//操作1

        if(C>1){
            //****0011 0101 0110 1001 1010 1100 状态3,5,6,9,10,12；
			//只有两个开关为打开状态，C可能为2+2的幂次
            //0011
            newstate=~42^36;
            if(mymap[newstate]==0) { state6[j++]=newstate; mymap[newstate]=1;}//

           //0101
            newstate=~36^21;
            if(mymap[newstate]==0) { state6[j++]=newstate; mymap[newstate]=1;}//

           //0110
            newstate=~42^21;
            if(mymap[newstate]==0) { state6[j++]=newstate; mymap[newstate]=1;}//
           //1001
            newstate=~36^63;
            if(mymap[newstate]==0) { state6[j++]=newstate; mymap[newstate]=1;}//
           //1010
            newstate=~42^63;
            if(mymap[newstate]==0) { state6[j++]=newstate; mymap[newstate]=1;}//
           //1100
            newstate=~21^63;
            if(mymap[newstate]==0) { state6[j++]=newstate; mymap[newstate]=1;}//

           //****1111 状态15；C可能为4+2的幂次
           if(C>=4){
             newstate=~21^63^36^42;
            if(mymap[newstate]==0) { state6[j++]=newstate; mymap[newstate]=1;}//
           }
        }

    }

    else {//C为奇数

        //****0001 0010 0100 1000 状态1,2,4,8；
		//只有一个开关为打开状态，C可能为1+2的幂次，奇数
        //0001
        newstate=~36;
        if(mymap[newstate]==0) { state6[j++]=newstate; mymap[newstate]=1;}//
        //0010
        newstate=~42;
        if(mymap[newstate]==0) { state6[j++]=newstate; mymap[newstate]=1;}//
        //0100
        newstate=~21;
        if(mymap[newstate]==0) { state6[j++]=newstate; mymap[newstate]=1;}//
        //1000
        newstate=~63;
        if(mymap[newstate]==0) { state6[j++]=newstate; mymap[newstate]=1;}//

        //****0111 1101 1011 1110 状态7,13,11,14；可能为3+2的幂次
        if(C>2){
                //0111
                newstate=~21^42^36;
                if(mymap[newstate]==0) { state6[j++]=newstate; mymap[newstate]=1;}//
                //1101
                newstate=~63^21^36;
                if(mymap[newstate]==0) { state6[j++]=newstate; mymap[newstate]=1;}//
                //1011
                newstate=~63^42^36;
                if(mymap[newstate]==0) { state6[j++]=newstate; mymap[newstate]=1;}//
                //1110
                newstate=~63^42^21;
                if(mymap[newstate]==0) { state6[j++]=newstate; mymap[newstate]=1;}//
        }
    }

//16种开关状态 （对应4种开关的状态）

//0000 状态0；C可能为0+2的幂次（等效按开关0次）
//1111 状态15；C可能为4+2的幂次（等效按开关4次）
//0011 0101 0110 1001 1010 1100 状态3,5,6,9,10,12；C可能为2+2的幂次（等效按开关2次）
//0001 0010 0100 1000 状态1,2,4,8；C可能为1+2的幂次，奇数（等效按开关1次）
//0111 1101 1011 1110 状态7,13,11,14；可能为3+2的幂次（等效按开关3次）
    sort(state6,state6+j);//
    int flag=0;
    for( int i=0;i<j;i++){
        int  decimal = state6[i];;			
		string s,ss;
		for(int j=5;j>-1;j--){
			if((decimal>>j)&1) ss="1";//整数化为二进制的字符串
			else	ss="0";
			s=s+ss;
		}

        if(check(s)){
            for(int i=0;i<N/6;i++) out<<s;
            string sTemp=s.substr(0,N%6);
            out<<sTemp<<endl;
            flag=1;
        }
    }
    if(!flag) {out<<"IMPOSSIBLE"<<endl;}
    return 0;

}



