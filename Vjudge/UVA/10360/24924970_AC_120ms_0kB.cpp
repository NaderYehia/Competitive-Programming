#include<bits/stdc++.h>

using namespace std;

const int N=2e3+5;
int t,n,m,d,cnt;
long long grid[1030][1030];

long long get(int i,int j){
    if(i<0||j<0)
        return 0;
    return grid[i][j];
}

int main() {
    scanf("%d",&t);
    while(t--){
        memset(grid,0,sizeof grid);
        scanf("%d%d",&d,&n);
        for(int i=0;i<n;++i){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            grid[a][b]=c;
        }

        for(int i=1;i<1025;++i)
            for(int j=1;j<1025;++j)
                grid[i][j]+=grid[i][j-1];
        for(int i=1;i<1025;++i)
            for(int j=1;j<1025;++j)
                grid[j][i]+=grid[j-1][i];

        long long mx=0;
        int f=0,s=0;
        for(int i=0;i<1025-d;++i){
            for(int j=0;j<1025-d;++j){
                long long here=get(i+d,j+d)+get(i-d-1,j-d-1)-get(i-d-1,j+d)-get(i+d,j-d-1);
                if(here>mx){
                    mx=max(mx,here);
                    f=i;
                    s=j;
                }
            }
        }
        printf("%d %d %d\n",f,s,mx);

    }
    return 0;
}
