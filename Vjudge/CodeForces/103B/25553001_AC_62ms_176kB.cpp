#include<bits/stdc++.h>

using namespace std;

const int N=2e3+5,OO=0x3f3f3f3f,M=1e9+7;
int t,n,m,k;
vector<int> adj[N];
bool vis[N];

void dfs(int u){
    vis[u]=1;
    for(int i=0,v;i<adj[u].size();++i){
        v=adj[u][i];
        if(!vis[v]) dfs(v);
    }
}

int main() {
    scanf("%d%d",&n,&m);
    if(n!=m){
        printf("NO\n");
        return 0;
    }
    for(int i=0,u,v;i<m;++i){
        scanf("%d%d",&u,&v);
        --u,--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cmp=0;
    for(int i=0;i<n;++i){
        if(!vis[i]) ++cmp,dfs(i);
    }
    cmp==1?printf("FHTAGN!\n"):printf("NO\n");
    return 0;
}
