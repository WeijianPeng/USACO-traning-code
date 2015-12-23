/*
ID:pen_wan1
LANG:C++
TASK:cowtour
*/
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <math.h>
#include <string.h>

using namespace std;

typedef struct point Point;
struct point{
    double x;
    double y;
};

double dst(point a,point b){
    return sqrt(  pow((a.x-b.x),2)+pow((a.y-b.y),2.0)  );}

double mymax(double a,double b){
    return a>b?a:b;}
double mymin(double a,double b){
    return a<b?a:b;}

Point P[150+5];
double adj[150+5][150+5];
double d[150+5][150+5];

int main()
{
    freopen("cowtour.in","r",stdin);
    freopen("cowtour.out","w",stdout);
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>P[i].x>>P[i].y;
    }
    for(int i=1;i<=N;i++){
        string s;
        cin>>s;
        for(int j=1;j<=N;j++){
            i==j?d[i][j]=0:d[i][j]=1000000;

            if(s[j-1]=='1'){
                    adj[i][j]=dst(P[i],P[j]);
                    d[i][j]=adj[i][j];
            }
        }
    }

//Floyd Warshall
for(int k=1;k<=N;k++)//顶点
    for(int j=1;j<=N;j++)
        for(int i=1;i<=N;i++){
            if(d[i][j]>d[i][k]+d[k][j])
                d[i][j]=d[i][k]+d[k][j];
        }

double rst=1000000;
double dMax[150+5];//初始化
memset(dMax,0,sizeof(dMax));

double rst1=0;
for(int j=1;j<=N;j++)
    for(int i=1;i<=N;i++)
    if(d[i][j]!=1000000){
        dMax[i]=mymax(dMax[i],d[i][j]);
        rst1=mymax(dMax[i],rst1);
        }

double newMax=1000000;
for(int i=1;i<=N;i++)
    for(int j=1;j<=N;j++)
    if(d[i][j]==1000000){
        newMax=mymin(dMax[i]+dst(P[i],P[j])+dMax[j],newMax);
        }

    rst=mymax(newMax,rst1);
    cout<<fixed<<setprecision(6)<<rst<< endl;//设置实数输出，保留6位有效数字
    return 0;
}