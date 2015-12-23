/*ID:pen_wan1
LANG:C++
TASK:maze1
*/
#include <iostream>
#include <cstdio>
#include <string.h>
#include <queue>

//#include <stdlib.h>

using namespace std;

vector <  vector <short int> > adj(3800);//利用二维向量实现 图的邻接表
int eexit[2+3];
int rst[3800];

queue <short int> q;

int W,H;
int max(int a,int b){
    if (a > b) return a;
    return b;
    }


int main()
{
    freopen("maze1.in","r",stdin);
    freopen("maze1.out","w",stdout);

    int e=0;
    cin>>W>>H;
    cin.get();

    for(int i=0;i<2*H+1;i++)
        for(int j=0;j<2*W+1+1;j++){//行尾读入‘\n’
            char c;
            c=cin.get();//逐个字符输入，cin的读入方式总是将前导的空格、回车滤掉，读入单词后到空格结束
            if(c=='\n') continue;
            if((i+1)%2==1) {//奇数行
                if(i==0&&c==' ')
                    {eexit[e]=(i/2)*W+j/2,e++;rst[(i/2)*W+j/2]=1;}  //第一行和最后一行上的出口格子
                else if(i==2*H&&c==' ')
                    {eexit[e]=(i/2-1)*W+j/2,e++;rst[(i/2-1)*W+j/2]=1;}
                else if(c==' '){
                        adj[(i/2-1)*W+j/2].push_back((i/2)*W+j/2);
                        adj[(i/2)*W+j/2].push_back((i/2-1)*W+j/2);
                        }//上一行格子和下一行格子相通
            }

            else {     //偶数行135奇数列024
                if(j==0&&c==' ')
                    {eexit[e]=(i/2)*W+j/2,e++;rst[(i/2)*W+j/2]=1;}
                else if(j==2*W&&c==' ')
                    {eexit[e]=(i/2)*W+j/2-1,e++;rst[(i/2)*W+j/2-1]=1;}
                else if(((j+1)%2==1)&&(c==' ')){
                        adj[(i/2)*W+j/2-1].push_back((i/2)*W+j/2);
                        adj[(i/2)*W+j/2].push_back((i/2)*W+j/2-1);
            }
        }
    }


    for(int i=0;i<e;i++){
         if(q.front()!=eexit[i]) q.push(eexit[i]);}

//BFS
     while(!q.empty()){//About 16MB datasize limit,About 1MB stacksize limit
        int node;
        node=q.front();
        q.pop();
        for(unsigned short int i=0;i<adj[node].size();i++){
                    if(rst[adj[node][i]]==0) {rst[adj[node][i]]=rst[node]+1,q.push(adj[node][i]);}
            }
        }

    int minimum=0;
    for(int i=0;i<W*H;i++)
        minimum=max(minimum,rst[i]);

    cout<<minimum<<endl;
    return 0;
}