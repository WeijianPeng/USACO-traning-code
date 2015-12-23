/*
ID:pen_wan1
LANG:C++
TASK:skidesign
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<cmath>
#include<algorithm>

using namespace std;
int N;
int h[1011];
int min(int a,int b){
	if(a>b)
		return b;
	else
		return a;
}

int main(){
    freopen("skidesign.in","r",stdin);
    freopen("skidesign.out","w",stdout);
    int i;
    cin >> N;
    for( i = 0; i < N; ++i)cin >> h[i];
    int ans = 0x7FFFFFFF;   //???
    for( i = 0; i < 100 - 17 + 1; ++i){
        int tans = 0;
        for(int j = 0; j < N; ++j){
            if(h[j] < i)tans += (i - h[j]) * (i - h[j]);
            if(h[j] > i + 17)tans += (h[j] - i - 17) * (h[j] - i - 17);
        }
        ans = min(ans, tans);
    }
    cout << ans << endl;
    return 0;
}