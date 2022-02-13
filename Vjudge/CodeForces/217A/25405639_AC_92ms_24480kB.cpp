#include<bits/stdc++.h>

using namespace std;

const int N=1e6+5,OO=0x3f3f3f3f;
int n;
vector<int> adj[N];
bool vis[N];

void dfs(int u){
    vis[u]=1;
    for(int i=0,v;i<adj[u].size();++i){
        v=adj[u][i];
        if(!vis[v])
            dfs(v);
    }
}

int main() {
    scanf("%d",&n);
    for(int i=0,u,v;i<n;++i){
        scanf("%d%d",&u,&v);
        --u,--v;
        u+=1000;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans=0;
    for(int i=0;i<N;++i){
        if(adj[i].size()&&!vis[i])
            dfs(i),++ans;
    }
    printf("%d",ans-1);
    return 0;
}
