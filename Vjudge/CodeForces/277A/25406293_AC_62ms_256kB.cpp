#include<bits/stdc++.h>

using namespace std;

const int N=1e6+5,OO=0x3f3f3f3f;
int n,m,k;
bool vis[2000];
vector<int> adj[2000];

void dfs(int u){
    vis[u]=1;
    for(int i=0,v;i<adj[u].size();++i){
        v=adj[u][i];
        if(!vis[v])
            dfs(v);
    }
}


int main() {
    bool nonz=0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        scanf("%d",&k);
        if(k)
            nonz=1;
        for(int j=0,v;j<k;++j){
            scanf("%d",&v);
            adj[i].push_back(v+1000);
            adj[v+1000].push_back(i);
        }
    }
    int ans=0;
    for(int i=0;i<n;++i){
        if(!vis[i])
            dfs(i),++ans;
    }
    printf("%d",ans-nonz);
    return 0;
}
