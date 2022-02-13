#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e2+10,M=2e4+7,OO=0x3f3f3f3f;
const double eps=1e-9;

double mem[10][10][N];

bool vis[10][10][N];

class ChessKnight{

public:
    double probability(int x, int y, int n){
        if(x<1||x>8||y<1||y>8) return 0;
        if(n==0) return 1.0;
        if(vis[x][y][n]) return mem[x][y][n];
        vis[x][y][n]=1;
        double ret=0;
        for(int i=-1;i<2;i+=2){
            for(int j=-1;j<2;j+=2){
                for(int k=0,ii=1,jj=2;k<2;++k,swap(ii,jj)){
                    int di=ii*i,dj=jj*j;
                    ret+=1.0/8*probability(x+di,y+dj,n-1);
                }
            }
        }
        return mem[x][y][n]=ret;
    }

};
