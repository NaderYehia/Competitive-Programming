#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e5+10,M=1e9+7,OO=0x3f3f3f3f;


int n,m;
vector<int> adj[N];
bool vis[N];

void dfs(int u){
    vis[u]=1;
    for(int i=0;i<adj[u].size();++i){
        int v=adj[u][i];
        if(!vis[v]) dfs(v);
    }
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    scanf("%d%d",&n,&m);

    for(int i=0;i<m;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        --u,--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int cmp=0;
    for(int i=0;i<n;++i)
        if(!vis[i]) dfs(i),++cmp;

    if(n==m&&cmp==1) puts("FHTAGN!");
    else puts("NO");

    return 0;
}
