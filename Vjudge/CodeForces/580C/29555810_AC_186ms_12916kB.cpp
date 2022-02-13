#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e5+10,M=1e9+7,OO=0x3f3f3f3f;


int n,m;
vector<int> adj[N];
int vis[N];
int cat[N];

int dfs(int u,int rem){
    vis[u]=1;
    if(adj[u].size()==1&&vis[adj[u][0]]) return 1;
    int ret=0;
    for(int i=0;i<adj[u].size();++i){
        int v=adj[u][i];
        if(vis[v]) continue;
        if(cat[v]&&rem>0) ret+=dfs(v,rem-cat[v]);
        else if(!cat[v]) ret+=dfs(v,m);
    }
    return ret;
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
        scanf("%d",cat+i);

    for(int i=0;i<n-1;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        --u,--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    printf("%d\n",dfs(0,m-cat[0]));

    return 0;
}