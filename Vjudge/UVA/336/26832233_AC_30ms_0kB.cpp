#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e5+5,M=1e9+7,OO=0x3f3f3f3f;
int t,n,m,k,ttl;
vector<int> adj[35];
bool vis[36];
map<int,int> enc;

int bfs(int u,int ttl,int nodes){
    memset(vis,0,sizeof vis);
    queue<pair<int,int> > q;
    q.push({u,ttl});
    vis[u]=1;
    while(q.size()){
        int curu=q.front().first;
        int curttl=q.front().second;
        q.pop();
        for(int i=0,v;i<adj[curu].size();++i){
            v=adj[curu][i];
            if(!vis[v]&&curttl){
                q.push({v,curttl-1}),vis[v]=1;
            }
        }
    }
    int cnt=0;
    for(int i=0;i<nodes;++i)
        if(!vis[i]) ++cnt;
    return cnt;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    int tc=1;
    while(~scanf("%d",&n),n){
        enc.clear();
        for(int i=0;i<35;++i)
            adj[i].clear();
        int j=0;
        for(int i=0,u,v;i<n;++i){
            scanf("%d%d",&u,&v);
            if(enc.find(u)==enc.end()) enc[u]=j++;
            if(enc.find(v)==enc.end()) enc[v]=j++;
            adj[enc[u]].push_back(enc[v]);
            adj[enc[v]].push_back(enc[u]);
        }
        while(~scanf("%d%d",&k,&ttl),(k+ttl)){
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",tc++,bfs(enc[k],ttl,j),k,ttl);
        }
    }
    return 0;
}
