#include<bits/stdc++.h>

using namespace std;

const int N=1e6+5,OO=0x3f3f3f3f;
int n,m,q;
vector<int> adj[105];
vector<int> col[105];
bool cols[105];
bool vis[105];
set<int> ans;

int dfs(int u,int c,int en){
    if(u==en){
        ans.insert(c);
        return 1;
    }
    vis[u]=1;
    int ans=0;
    for(int i=0,v;i<adj[u].size();++i){
        v=adj[u][i];
        if(!vis[v]&&col[u][i]==c){
            ans+=dfs(v,c,en);
        }
    }
    vis[u]=0;
    return ans;
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=0,u,v,c;i<m;++i){
        scanf("%d%d%d",&u,&v,&c);
        adj[u].push_back(v);
        col[u].push_back(c);
        adj[v].push_back(u);
        col[v].push_back(c);
    }
    scanf("%d",&q);
    while(q--){
        int u,v;
        scanf("%d%d",&u,&v);
        ans.clear();
        for(int i=0;i<adj[u].size();++i){
            vis[u]=1;
            dfs(adj[u][i],col[u][i],v);
            vis[u]=0;
        }
        printf("%d\n",ans.size());
    }
    return 0;
}
