#include<bits/stdc++.h>

using namespace std;

const int N=2e2+5;
int grid[400][400];
int t,n;


int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                scanf("%d",&grid[i][j]),grid[i][j+n]=grid[i+n][j]=grid[i+n][j+n]=grid[i][j];
        for(int i=0;i<2*n;++i){
            for(int j=0;j<2*n;++j){
                if(i>0) grid[i][j]+=grid[i-1][j];
                if(j>0) grid[i][j]+=grid[i][j-1];
                if(i>0&&j>0) grid[i][j]-=grid[i-1][j-1];
            }
        }
        int mx=-1000000000;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                for(int c=0;c<n;++c){
                    for(int r=0;r<n;++r){
                        if(c+i>=2*n) break;
                        if(r+j>=2*n) break;
                        int curSum=grid[i+c][r+j];
                        if(i>0) curSum-=grid[i-1][r+j];
                        if(j>0) curSum-=grid[c+i][j-1];
                        if(i>0&&j>0) curSum+=grid[i-1][j-1];
                        mx=max(curSum,mx);
                    }
                }
            }
        }
        printf("%d\n",mx);
    }
    return 0;
}

