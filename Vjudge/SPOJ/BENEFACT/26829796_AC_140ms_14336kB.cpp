#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e5+5,M=1e9+7,OO=0x3f3f3f3f;
int t,n,m,k;
vector<int> adj[N];
vector<int> cst[N];
ll dis[N];

pair<int,ll> bfs(int u){
    memset(dis,-1,sizeof dis);
    queue< int > q;
    q.push(u);
    dis[u]=0;
    while(q.size()){
        int cur=q.front();
        q.pop();
        for(int i=0,v;i<adj[cur].size();++i){
            v=adj[cur][i];
            if(dis[v]==-1){
                q.push(v),dis[v]=dis[cur]+cst[cur][i];
            }
        }
    }
    int mxu=1,mxlen=0;
    for(int i=1;i<=n;++i){
        if(dis[i]>mxlen)
            mxlen=dis[i],mxu=i;
    }
    return {mxu,mxlen};
}

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d\n",&n);
        for(int i=1;i<=n;++i)
            adj[i].clear(),cst[i].clear();
        for(int i=1,u,v,c;i<n;++i){
            scanf("%d%d%d",&u,&v,&c);
            adj[u].push_back(v);
            cst[u].push_back(c);
            adj[v].push_back(u);
            cst[v].push_back(c);
        }
        pair<int,ll> ans=bfs(1);
        ans=bfs(ans.first);
        printf("%lld\n",ans.second);
    }
    return 0;
}
