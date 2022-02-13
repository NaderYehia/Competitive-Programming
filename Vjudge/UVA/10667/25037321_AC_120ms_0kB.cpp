#include<bits/stdc++.h>

using namespace std;

const int N=1e2+5;
int t,n,b;
int grid[N][N];

int main() {
    scanf("%d",&t);
    while(t--){
        memset(grid,0,sizeof grid);
        scanf("%d%d",&n,&b);
        while(b--){
            int r1,c1,r2,c2;
            scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
            for(int i=r1;i<=r2;++i){
                for(int j=c1;j<=c2;++j){
                    grid[i][j]=1;
                }
            }
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                grid[i][j]+=grid[i-1][j]+grid[i][j-1]-grid[i-1][j-1];
            }
        }
        int mx=0;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                for(int l=i;l<=n;++l){
                    for(int r=j;r<=n;++r){
                        if(grid[l][r]-grid[i-1][r]-grid[l][j-1]+grid[i-1][j-1]==0)
                            mx=max(mx,(l-i+1)*(r-j+1));
                    }
                }
            }
        }
        printf("%d\n",mx);
    }
    return 0;
}
