#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e5+5,M=1e9+7,OO=0x3f3f3f3f;
int t,n,m,k;
vector<int> adj[N];
int enc[N];
int dis[N];
bool vis[N];

int dfs(int u){
    vis[u]=1;
    int cnt=1;
    for(int i=0,v;i<adj[u].size();++i){
        v=adj[u][i];
        if(!vis[v]){
            cnt+=dfs(v);
        }
    }
    vis[u]=0;
    return dis[u]=cnt;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    int tc=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            adj[i].clear();
        memset(vis,0,sizeof vis);
        memset(dis,-1,sizeof dis);

        for(int i=0,u,v;i<n;++i){
            scanf("%d%d",&u,&v);
            adj[u].push_back(v);
        }

        int mx=0,idx=-1;
        for(int i=1;i<=n;++i){
            if(dis[i]==-1){
                dis[i]=dfs(i);
            }
            if(dis[i]>mx){
                mx=dis[i];
                idx=i;
            }
        }

        printf("Case %d: %d\n",tc++,idx);
    }
    return 0;
}
