#include<bits/stdc++.h>

using namespace std;

const int N=1e3+5,OO=0x3f3f3f3f;
int t,n,m,k;
string grid[30];
bool vis[30][30];

bool valid(int u,int v){
    return u>-1&&v>-1&&u<n&&v<m;
}

int dfs(int u,int v){
    vis[u][v]=1;
    int ans=1;
    for(int i=-1;i<2;++i){
        for(int j=-1;j<2;++j){
            if(valid(u+i,v+j)&&!vis[u+i][v+j]&&grid[u+i][v+j]=='1')
                ans+=dfs(u+i,v+j);
        }
    }
    return ans;
}

int main() {
    scanf("%d\n\n",&t);
    while(t--){
        string s;
        n=0,m=0;
        while(getline(cin,s),s.length()){
            grid[n++]=s;
            m=s.length();
        }
        memset(vis,0,sizeof vis);
        int ans=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(!vis[i][j]&&grid[i][j]=='1')
                    ans=max(ans,dfs(i,j));
            }
        }
        printf("%d\n",ans);
        if(t)
            printf("\n");
    }
    return 0;
}
