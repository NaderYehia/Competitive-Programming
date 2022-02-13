#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e2+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m,q;
int from,to,trips,mx;
vector<pair<int,int> > adj[N];
bool vis[N];

bool can(int u,int x){
    if(u==to) return 1;
    vis[u]=1;
    bool ret=0;
    for(int i=0;i<adj[u].size();++i){
        int v=adj[u][i].first;
        int c=adj[u][i].second;
        if(!vis[v]&&c>x) ret|=can(v,x);
    }
    return ret;
}

int bs(){
    int lo=1,hi=trips,md;
    while(lo<hi){
        md=lo+(hi-lo)/2;
        memset(vis,0,sizeof vis);
        if(can(from,trips/md+(trips%md>0))) hi=md;
        else lo=md+1;
    }
    return lo;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("myfile.txt","w",stdout);
    int tc=1;
    while(~scanf("%d%d",&n,&m),n+m){
        for(int i=0;i<n;++i)
            adj[i].clear();
        for(int i=0;i<m;++i){
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            adj[--u].push_back({--v,c});
            adj[v].push_back({u,c});
        }
        scanf("%d%d%d",&from,&to,&trips);
        --from,--to;
        printf("Scenario #%d\n",tc++);
        printf("Minimum Number of Trips = %d\n\n",bs());
    }
    return 0;
}
