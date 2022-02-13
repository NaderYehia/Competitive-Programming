#include<bits/stdc++.h>

using namespace std;

const int N=3e4+5,OO=0x3f3f3f3f;
int t,n,m,k;
vector<int> adj[N];
bool vis[N];

int dfs(int u){
    vis[u]=1;
    int ans=1;
    for(int i=0,v;i<adj[u].size();++i){
        v=adj[u][i];
        if(!vis[v])
            ans+=dfs(v);
    }
    return ans;
}

int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;++i)
            adj[i].clear();
        for(int i=0,u,v;i<m;++i){
            scanf("%d%d",&u,&v);
            --u,--v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        memset(vis,0,sizeof vis);
        int ans=0;
        for(int i=0;i<n;++i){
            if(!vis[i])
                ans=max(ans,dfs(i));
        }
        printf("%d\n",ans);
    }
    return 0;
}
