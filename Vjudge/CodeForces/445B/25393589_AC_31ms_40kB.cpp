#include<bits/stdc++.h>

using namespace std;

const int N=1e3+5,OO=0x3f3f3f3f;
int t,n,m,k,nedges;
vector<int> adj[60];
bool vis[60];

int dfs(int u){
    vis[u]=1;
    int ret=1;
    for(int i=0,v;i<adj[u].size();++i){
        v=adj[u][i];
        if(!vis[v])
            ret+=dfs(v);
    }
    return ret;
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=0,u,v;i<m;++i){
        scanf("%d%d",&u,&v);
        --u,--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    long long ans=1,t=1;
    for(int i=0;i<n;++i){
        if(!vis[i]){
            ans*=pow(2,dfs(i)-1);
        }
    }
    printf("%lld",ans);
    return 0;
}
