#include<bits/stdc++.h>

using namespace std;

const int N=3e4+5;
int n,x,y;
int grid[105][105];

int main() {
    while(~scanf("%d",&n)){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                scanf("%d",grid[i]+j);
                if(i>0) grid[i][j]+=grid[i-1][j];
                if(j>0) grid[i][j]+=grid[i][j-1];
                if(i>0&&j>0) grid[i][j]-=grid[i-1][j-1];
            }
        }
        int mx=-127;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                for(int l=i;l<n;++l){
                    for(int r=j;r<n;++r){
                        int subRec=grid[l][r];
                        if(i>0&&j>0) subRec+=grid[i-1][j-1];
                        if(i>0) subRec-=grid[i-1][r];
                        if(j>0) subRec-=grid[l][j-1];
                        mx=max(mx,subRec);
                    }
                }
            }
        }
        printf("%d\n",mx);
    }
    return 0;
}
