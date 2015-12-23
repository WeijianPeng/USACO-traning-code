/*
ID:pen_wan1
LANG:C++
TASK:ttwo
*/


#include <iostream>
#include <stdio.h>

using namespace std;

//struct 定义1 正规
typedef struct coordinateDirection CoorDir;
struct coordinateDirection{
    int x, y;
    int dir;
    };

//struct定义2
//typedef struct coordinate{
//    int x,y;
//    }Coordinate;

//struct定义3
//typedef struct coordinate{
//    int x,y;
//    }Coordinate;


char mesh[10+5][10+5];
int vis[10][10][4][10][10][4]; //牛和农民走过的位置（格子+方向记录0123 东西南北）
int flag;
int time1;

CoorDir search(CoorDir a ){
    switch (a.dir){
        case 0:if(mesh[a.x-1][a.y]=='*'||a.x-1<0) {a.dir=1;return a;  }//north
                 else {a.x=a.x-1;return a;  }
        case 1:if(mesh[a.x][a.y+1]=='*'||a.y+1>9) {a.dir=2;return a;  }//east
                 else {a.y=a.y+1;return a;  }
        case 2:if(mesh[a.x+1][a.y]=='*'||a.x+1>9) {a.dir=3;return a;  }//south
                 else {a.x=a.x+1;return a;  }
        case 3:if(mesh[a.x][a.y-1]=='*'||a.y-1<0) {a.dir=0;return a;  }//west
                 else {a.y=a.y-1;return a;  }
        default:{cout <<"error!";}
    }
}
void wander(CoorDir cowC,CoorDir farmerC){
    if(vis[cowC.x][cowC.y][cowC.dir][farmerC.x][farmerC.y][farmerC.dir]==1)
        return ;
    if(cowC.x==farmerC.x&&cowC.y==farmerC.y){flag=1;return;}

    vis[cowC.x][cowC.y][cowC.dir][farmerC.x][farmerC.y][farmerC.dir]=1;
    time1++;
    CoorDir nextCowC=search(cowC);
    CoorDir nextFarmerC=search(farmerC);

    wander(nextCowC,nextFarmerC);
}

int main()
{
    freopen("ttwo.in","r",stdin);
    freopen("ttwo.out","w",stdout);

    CoorDir cowPosition,farmerPosition;
    cowPosition.dir=0,farmerPosition.dir=0;

    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++){
            cin >> mesh[i][j];
            if(mesh[i][j]=='C') cowPosition.x=i,cowPosition.y=j;
            if(mesh[i][j]=='F') farmerPosition.x=i,farmerPosition.y=j;
        }

    wander(cowPosition,farmerPosition);

    if(flag) cout<<time1<<endl;
    else     cout<<0<<endl;

    return 0;
}