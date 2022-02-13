#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=2e2+10,M=1e9+7,OO=0x3f3f3f3f;

vector<int> adj[N];
int vis[N],vid;
bool col[N];

void init(int n){
    ++vid;
    for(int i=0;i<n;++i)
        adj[i].clear();
}

bool dfs(int u,bool c){
    vis[u]=vid;
    col[u]=c;
    bool ret=1;
    for(int i=0;i<adj[u].size();++i){
        int v=adj[u][i];
        if(vis[v]==vid&&col[v]==col[c]) return 0;
        else if(vis[v]!=vid) ret&=dfs(v,!c);
    }
    return ret;
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int n,m;
    while(~scanf("%d%d",&n,&m),n){
        init(n);
        for(int i=0;i<m;++i){
            int u,v;
            scanf("%d%d",&u,&v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        puts(dfs(0,0)?"BICOLORABLE.":"NOT BICOLORABLE.");
    }

    return 0;
}
