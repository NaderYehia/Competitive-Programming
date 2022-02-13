#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e5+10,M=2e4+7,OO=0x3f3f3f3f;
const double eps=1e-9;

vector<int> adj[N];

int dep[N];
bool leaf[N];
double prob[N];

void dfs(int u,int p,int d,double pb){
    dep[u]=d;
    prob[u]=pb;
    if(adj[u].size()==1) leaf[u]=1;
    for(int i=0;i<adj[u].size();++i){
        int v=adj[u][i];
        if(v==p) continue;
        dfs(v,u,d+1,pb/(adj[u].size()-(p==-1?0:1)));
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

    dfs(0,-1,0,1.0);

    double ans=0;
    for(int i=0;i<n;++i)
        if(leaf[i]) ans+=dep[i]*prob[i];

    printf("%.15f",ans);

    return 0;
}
