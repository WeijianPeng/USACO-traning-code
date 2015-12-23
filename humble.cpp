/*
ID:pen_wan1
TASK:humble
LANG:C++
*/
#include <iostream>
#include <cstdio>

using namespace std;

int K,N;
int prime[100000+5];
int vis[100000+5];//��¼prime����p,p*hС��h�������
long int rst[100000+5];

int min(int a, int b){
    if (a>b) return b;
    else return a;
}
int main()
{
    freopen("humble.in","r",stdin);
    freopen("humble.out","w",stdout);

    cin>>K>>N;
    for(int i=0;i<K;i++){
        cin>>prime[i];
    }

//     initialize
    //����ÿ������pѰ����С�ĳ���h, ʹ��h*p����һ��������,ȡ�����ҵ���h*p����С��һ����
    rst[0]=1;

    for(int i=1;i<=N;i++){
        rst[i]=2000000000;
        int minVis;
        for(int k=0;k<K;k++){
            for(;rst[vis[k]]*prime[k]<=rst[i-1];){
                vis[k]++;}

            if(rst[vis[k]]*prime[k]<rst[i])
            {rst[i]=rst[vis[k]]*prime[k];minVis=k;}
        }
        vis[minVis]++;
    }
    cout<<rst[N] << endl;

    return 0;
}


// /*
// ID:pen_wan1
// TASK:humble
// LANG:C++
// */
// #include <iostream>
// #include <cstdio>

// using namespace std;

// int K,N;
// int prime[100000+5];
// int vis[100000+5];//��¼prime����p,p*hС��h�������
// long int rst[100000+5];

// int min(int a, int b){
    // if (a>b) return b;
    // else return a;
// }
// int main()
// {
    // freopen("humble.in","r",stdin);
    // freopen("humble.out","w",stdout);

    // cin>>K>>N;
    // for(int i=0;i<K;i++){
        // cin>>prime[i];
    // }

// //     initialize
    // //����ÿ������pѰ����С�ĳ���h, ʹ��h*p����һ��������,ȡ�����ҵ���h*p����С��һ����
    // rst[0]=1;

    // for(int i=1;i<=N;i++){
        // long int temp=2100000000;
        // for(int k=0;k<K;k++){
                // for(int j=vis[k];j<i;j++){
                    // if(rst[j]*prime[k]>rst[i-1])
                        // {temp=min(temp,rst[j]*prime[k]);vis[k]=j;break;}
                // }
        // }
        // rst[i]=temp;
    // }
    // cout<<rst[N] << endl;

    // return 0;
// }



// /*
// ID:pen_wan1
// TASK:humble
// LANG:C++
// */
// #include <iostream>
// #include <cstdio>

// using namespace std;

// int K,N;
// long int prime[100000+5];
// long int rst[100000+5];

// int min(int a, int b){
    // if (a>b) return b;
    // else return a;
// }
// int main()
// {
    // freopen("humble.in","r",stdin);
    // freopen("humble.out","w",stdout);

    // cin>>K>>N;
    // for(int i=0;i<K;i++){
        // cin>>prime[i];
    // }

    // initialize
    // ����ÿ������pѰ����С�ĳ���h, ʹ��h*p����һ��������,ȡ�����ҵ���h*p����С��һ����
    // rst[0]=1;

    // for(int i=1;i<=N;i++){
        // long int temp=100000000;
        // for(int j=0;j<i;j++){
            // for(int k=0;k<N;k++)
            // if(rst[j]*prime[k]>rst[i-1])
                // {temp=min(temp,rst[j]*prime[k]);}
        // }
        // rst[i]=temp;
    // }
    // cout<<rst[N] << endl;

    // return 0;
// }
