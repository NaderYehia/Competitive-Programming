#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5,OO=0x3f3f3f3f;
int t,n,m,k;
vector<int> adj[N];
bool cats[N];
bool vis[N];

int dfs(int u,int rem){
    vis[u]=1;
    if(adj[u].size()==1&&u!=0)
        return 1;
    int ans=0;
    for(int i=0,v;i<adj[u].size();++i){
        v=adj[u][i];
        if(!vis[v]){
            if(cats[v]){
                if(rem)
                    ans+=dfs(v,rem-1);
            }
            else ans+=dfs(v,m);
        }
    }
    return ans;
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
        scanf("%d",cats+i);
    for(int i=0,u,v;i<n-1;++i){
        scanf("%d%d",&u,&v);
        --u,--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    printf("%d",dfs(0,m-cats[0]));
    return 0;
}
