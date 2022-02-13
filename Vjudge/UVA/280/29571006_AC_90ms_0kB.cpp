#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e2+10,M=2e9+7,OO=0x3f3f3f3f;

vector<int> adj[N];
int vis[N],vid;

void dfs(int u){
    for(int i=0;i<adj[u].size();++i){
        int v=adj[u][i];
        if(vis[v]!=vid){
            vis[v]=vid;
            dfs(v);
        }
    }
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int n;
    while(~scanf("%d",&n),n){
        for(int i=0;i<=n;++i)
            adj[i].clear();
        int u;
        while(scanf("%d",&u),u){
            int v;
            while(scanf("%d",&v),v){
                adj[u].push_back(v);
            }
        }
        int m;
        scanf("%d",&m);
        while(m--){
            int u;
            scanf("%d",&u);

            ++vid;
            dfs(u);

            vector<int> vec;
            for(int i=1;i<=n;++i)
                if(vis[i]!=vid)
                    vec.push_back(i);

            printf("%d",vec.size());
            for(int i=0;i<vec.size();++i)
                printf(" %d",vec[i]);
            puts("");
        }
    }


    return 0;
}
