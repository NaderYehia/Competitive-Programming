#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=2e5+10,M=1e9+7,OO=0x3f3f3f3f;

vector<int> adj[N];
bool vis[N];
vector<int> ans;

void dfs(int u){
    vis[u]=1;
    for(int i=0;i<adj[u].size();++i){
        int v=adj[u][i];
        if(!vis[v]) dfs(v);
    }
    ans.push_back(u);
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int n,m;
    while(~scanf("%d%d",&n,&m),n||m){
        ans.clear();
        for(int i=0;i<n;++i){
            adj[i].clear();
            vis[i]=0;
        }
        for(int i=0;i<m;++i){
            int u,v;
            scanf("%d%d",&u,&v);
            --u,--v;
            adj[v].push_back(u);
        }

        for(int i=0;i<n;++i){
            if(!vis[i]){
                dfs(i);
            }
        }

        for(int i=0;i<ans.size();++i)
            printf("%d%c",ans[i]+1," \n"[i+1==ans.size()]);

    }


    return 0;
}
