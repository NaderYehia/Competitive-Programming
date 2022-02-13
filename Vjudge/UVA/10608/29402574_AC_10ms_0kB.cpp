#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=2e5+10,M=1e9+7,OO=0x3f3f3f3f;

vector<int> adj[N];
bool vis[N];
int ans,cnt;

void dfs(int u){
    vis[u]=1;
    ++cnt;
    for(int i=0;i<adj[u].size();++i){
        int v=adj[u][i];
        if(!vis[v]) dfs(v);
    }
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;++i)
            adj[i].clear();
        memset(vis,0,n*sizeof vis[0]);
        for(int i=0;i<m;++i){
            int u,v;
            scanf("%d%d",&u,&v);
            --u,--v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        ans=0;
        for(int i=0;i<n;++i){
            if(!vis[i]){
                cnt=0;
                dfs(i);
                ans=max(ans,cnt);
            }
        }
        printf("%d\n",ans);

    }

    return 0;
}
