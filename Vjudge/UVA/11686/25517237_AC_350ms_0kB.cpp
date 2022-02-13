#include<bits/stdc++.h>

using namespace std;

const int N=1e6+5,OO=0x3f3f3f3f,M=1e9+7;
int t,n,m,k,cnt;
vector<int> adj[N];
int in[N];
bool vis[N];
vector<int>ans;

void dfs(int u){
    ans.push_back(u);
    vis[u]=1;
    for(int i=0,v;i<adj[u].size();++i){
        v=adj[u][i];
        if(!vis[v]){
            --in[v];
            if(in[v]==0) dfs(v);
        }
    }
}

int main() {
    while(scanf("%d%d",&n,&m),(n+m)){
        for(int i=0;i<n;++i)
            adj[i].clear();
        ans.clear();
        memset(in,0,sizeof in);
        memset(vis,0,sizeof vis);
        cnt=0;
        for(int i=0,u,v;i<m;++i){
            scanf("%d%d",&u,&v);
            --u,--v;
            adj[u].push_back(v);
            ++in[v];
        }
        for(int i=0;i<n;++i){
            if(!vis[i]&&in[i]==0){
                dfs(i);
            }
        }
        bool failed=0;
        for(int i=0;i<n;++i){
            if(!vis[i])
                failed=1;
        }
        if(failed){
            printf("IMPOSSIBLE\n");
        }else{
            for(int i=0;i<ans.size();++i)
                printf("%d\n",ans[i]+1);
        }
    }
    return 0;
}
