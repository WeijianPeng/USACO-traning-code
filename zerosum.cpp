/*
ID:pen_wan1
LANG:C++
TASK:zerosum
*/

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
int N;
int cnt;
char output[9];

void print(){
    int i;
    for( i=1;i<N;i++){
        cout<<i<<output[i];
    }
    cout<<i<<endl;
}

void dfs(int n,int sum,int lastOptnum, int typ){

    if(n>0){
        if(typ==1){
            output[n-1]=' ';
        }

        else if(typ==2){
            output[n-1]='+';
        }

        else{
            output[n-1]='-';
        }
   }

    if(sum==0&&n==N){
            print();return;
    }
    else if(n==N) return;

    if(lastOptnum>0)
        dfs(n+1,sum-lastOptnum+lastOptnum*10+n+1,lastOptnum*10+n+1,1);
    else  dfs(n+1,sum-lastOptnum+lastOptnum*10-n-1,lastOptnum*10-n-1,1);

    dfs(n+1,sum+n+1,n+1,2);

    dfs(n+1,sum-n-1,-n-1,3);


}

int main()
{
    freopen("zerosum.in","r",stdin);
    freopen("zerosum.out","w",stdout);
    cin>>N;

    dfs(1,1,1,0);

    return 0;
}
