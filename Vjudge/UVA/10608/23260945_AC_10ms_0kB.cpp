#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
const int oo=0x3f3f3f3f;

vector<int> adj[N];
int q,n,m,u,v,mx,x;
bool vis[N];

void dfs(int u){
    ++x;
    vis[u]=1;
    for(int v : adj[u])
        if(!vis[v])
            dfs(v);
}


int main(){
        scanf("%d",&q);
        while(q--){
            memset(vis,0,sizeof vis);
            for(int i=0;i<n;++i)
                adj[i].clear();
            scanf("%d %d",&n,&m);
            for(int i=0;i<m;++i){
                scanf("%d %d",&u,&v);
                --u,--v;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            mx=0;
            for(int i=0;i<n;++i){
                if(!vis[i]){
                    dfs(i);
                    mx=max(mx,x);
                    x=0;
                }
            }
            printf("%d\n",mx);
        }
}
