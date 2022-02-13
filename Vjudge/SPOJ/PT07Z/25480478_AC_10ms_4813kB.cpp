#include<bits/stdc++.h>

using namespace std;

const int N=1e4+5,OO=0x3f3f3f3f,M=1e9+7;
int t,n,m;
vector<int> adj[N];
bool vis[N];

pair<int,int> bfs(int ft){
    queue<pair<int,int> > q;
    q.push({ft,0});
    vis[ft]=1;
    int mx=0,idx=ft;
    while(q.size()){
        int u=q.front().first;
        int sz=q.front().second;
        q.pop();
        if(sz>mx){
            mx=sz;
            idx=u;
        }
        for(int i=0,v;i<adj[u].size();++i){
            v=adj[u][i];
            if(!vis[v]){
                vis[v]=1;
                q.push({v,sz+1});
            }
        }
    }
    return {idx,mx};
}

int main() {
    scanf("%d",&n);
    for(int i=0,u,v;i<n-1;++i){
        scanf("%d%d",&u,&v);
        --u,--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    pair<int,int> pr=bfs(0);
    memset(vis,0,sizeof vis);
    cout<<bfs(pr.first).second;
    return 0;
}
