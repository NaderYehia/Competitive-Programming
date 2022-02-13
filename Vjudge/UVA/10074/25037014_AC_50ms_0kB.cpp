#include<bits/stdc++.h>

using namespace std;

const int N=1e2+5;
int t,n,m,x;
int grid[N][N];

int main() {
    while(~scanf("%d%d",&n,&m),(n+m)){
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                scanf("%d",grid[i]+j);
                if(i>0) grid[i][j]+=grid[i-1][j];
                if(j>0) grid[i][j]+=grid[i][j-1];
                if(i>0&&j>0) grid[i][j]-=grid[i-1][j-1];
            }
        }
        int mx=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                for(int l=i;l<n;++l){
                    for(int r=j;r<m;++r){
                        if(grid[l][r]+((i>0&&j>0)?grid[i-1][j-1]:0)-(i>0?grid[i-1][r]:0)-(j>0?grid[l][j-1]:0)==0)
                            mx=max(mx,(l-i+1)*(r-j+1));
                    }
                }
            }
        }
        printf("%d\n",mx);
    }
    return 0;
}
