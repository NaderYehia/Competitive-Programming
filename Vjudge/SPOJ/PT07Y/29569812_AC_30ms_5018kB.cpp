#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e4+10,M=2e9+7,OO=0x3f3f3f3f;

vector<int> adj[N];
bool vis[N];

int dfs(int u){
    vis[u]=1;
    int ret=1;
    for(int i=0;i<adj[u].size();++i){
        int v=adj[u][i];
        if(!vis[v]) ret+=dfs(v);
    }
    return ret;
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);


    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        --u,--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(n-1==m&&dfs(0)==n) printf("YES\n");
    else printf("NO\n");


    return 0;
}
