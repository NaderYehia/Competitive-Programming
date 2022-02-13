#include<bits/stdc++.h>
 
using namespace std;
 
const int N=2e5+5,OO=0x3f3f3f3f;
int t,n,m,k;
vector<int> adj[N];
int lvl[N];
int anc[N];
bool vis[N];
bool chosen[N];
 
void bfs(){
    memset(lvl,-1,sizeof lvl);
    queue<int> q;
    q.push(0);
    lvl[0]=0;
    while(q.size()){
        int u=q.front();
        q.pop();
        for(int i=0,v;i<adj[u].size();++i){
            v=adj[u][i];
            if(lvl[v]==-1)
                q.push(v),lvl[v]=lvl[u]+1;
        }
    }
}
 
int dfs(int u){
    vis[u]=1;
    int ret=1;
    for(int i=0,v;i<adj[u].size();++i){
        v=adj[u][i];
        if(!vis[v]){
            ret+=dfs(v);
        }
    }
    return anc[u]=ret;
}
 
int tmp;
long long ans;
void cnt(int u){
    vis[u]=1;
    if(chosen[u])
        ans+=tmp;
    else ++tmp;
    for(int i=0,v;i<adj[u].size();++i){
        v=adj[u][i];
        if(!vis[v])
            cnt(v);
    }
    if(!chosen[u])
        --tmp;
}
 
int main() {
    scanf("%d%d",&n,&k);
    for(int i=0,u,v;i<n-1;++i){
        scanf("%d%d",&u,&v);
        --u,--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs();
    dfs(0);
    vector<pair<int,int> > v;
    for(int i=0;i<n;++i){
        v.push_back({lvl[i]-anc[i],i});
    }
    sort(v.rbegin(),v.rend());
    for(int i=0;i<k;++i)
        chosen[v[i].second]=1;
    memset(vis,0,sizeof vis);
    cnt(0);
    printf("%lld",ans);
    return 0;
}