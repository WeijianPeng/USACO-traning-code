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

vector <  vector <short int> > adj(3800);//���ö�ά����ʵ�� ͼ���ڽӱ�
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
        for(int j=0;j<2*W+1+1;j++){//��β���롮\n��
            char c;
            c=cin.get();//����ַ����룬cin�Ķ��뷽ʽ���ǽ�ǰ���Ŀո񡢻س��˵������뵥�ʺ󵽿ո����
            if(c=='\n') continue;
            if((i+1)%2==1) {//������
                if(i==0&&c==' ')
                    {eexit[e]=(i/2)*W+j/2,e++;rst[(i/2)*W+j/2]=1;}  //��һ�к����һ���ϵĳ��ڸ���
                else if(i==2*H&&c==' ')
                    {eexit[e]=(i/2-1)*W+j/2,e++;rst[(i/2-1)*W+j/2]=1;}
                else if(c==' '){
                        adj[(i/2-1)*W+j/2].push_back((i/2)*W+j/2);
                        adj[(i/2)*W+j/2].push_back((i/2-1)*W+j/2);
                        }//��һ�и��Ӻ���һ�и�����ͨ
            }

            else {     //ż����135������024
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