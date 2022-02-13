#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e4+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int n,m,grid[105][105];
int mem[105][105];


int solve(int i,int j){
    if(i==n) return 0;
    int &ret=mem[i][j];
    if(~ret) return ret;
    ret=max(ret,solve(i+1,j)+grid[i][j]);
    if(j+1<m) ret=max(ret,grid[i][j]+solve(i+1,j+1));
    if(j-1>-1) ret=max(ret,grid[i][j]+solve(i+1,j-1));
    return ret;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                scanf("%d",grid[i]+j);
        memset(mem,-1,sizeof mem);
        int ans=0;
        for(int i=0;i<m;++i)
            ans=max(ans,solve(0,i));
        printf("%d\n",ans);
    }
    return 0;
}
