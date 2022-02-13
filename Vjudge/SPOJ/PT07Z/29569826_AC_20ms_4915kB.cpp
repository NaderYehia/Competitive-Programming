#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e4+10,M=2e9+7,OO=0x3f3f3f3f;

vector<int> adj[N];
int vis[N],vid;

int mx,id;

void dfs(int u,int dep){
    vis[u]=vid;
    if(dep>mx){
        mx=dep;
        id=u;
    }
    for(int i=0;i<adj[u].size();++i){
        int v=adj[u][i];
        if(vis[v]!=vid) dfs(v,dep+1);
    }
}


int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);


    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        --u,--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ++vid;
    dfs(0,0);

    ++vid;
    dfs(id,0);

    printf("%d\n",mx);

    return 0;
}
