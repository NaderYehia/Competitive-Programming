#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5,OO=0x3f3f3f3f,M=1e9+7;
int t,n,m,k,cnt;
vector<int> adj[105];
int in[105];
bool vis[105];

void dfs(int u){
    ++cnt;
    printf("%d%c",u+1," \n"[cnt==n]);
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
    }
    return 0;
}
