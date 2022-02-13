#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e2+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m,q;
vector<int> adj[N];
vector<int> cost[N];
int order[N*N];
int lu[N*N],lv[N*N],lc[N*N];
int first,second,mn;
bool vis0[N];
bool vis1[N];
int to[N];

void dfs1(int u){
    if(first+second>mn) return;
    if(u==n-1){
        mn=min(mn,first+second);
        return;
    }
    vis1[u]=1;
    for(int i=0;i<adj[u].size();++i){
        int v=adj[u][i];
        int c=cost[u][i];
        if(to[u]==v) continue;
        if(!vis1[v]){
            second+=c;
            dfs1(v);
            second-=c;
        }
    }
    vis1[u]=0;
}

void dfs0(int u){
    if(first+second>mn) return;
    if(u==n-1){
        dfs1(0);
        return;
    }
    vis0[u]=1;
    for(int i=0;i<adj[u].size();++i){
        int v=adj[u][i];
        int c=cost[u][i];
        if(!vis0[v]){
            to[u]=v;
            first+=c;
            dfs0(v);
            to[u]=-1;
            first-=c;
        }
    }
    vis0[u]=0;
}

bool cmp(int i,int j){
    return lc[i]<lc[j];
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("myfile.txt","w",stdout);
    while(~scanf("%d",&n),n){
        for(int i=0;i<n;++i)
            adj[i].clear(),cost[i].clear();
        scanf("%d",&m);
        for(int i=0;i<m;++i){
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            lu[i]=u,lv[i]=v,lc[i]=c,order[i]=i;
        }
        sort(order,order+m,cmp);
        for(int i=0;i<m;++i){
            int u=lu[order[i]],v=lv[order[i]],c=lc[order[i]];
            --u,--v;
            adj[u].push_back(v);
            cost[u].push_back(c);
            adj[v].push_back(u);
            cost[v].push_back(c);
        }
        memset(to,-1,sizeof to);
        mn=OO;first=second=0;
        dfs0(0);
        if(mn>=OO) printf("Back to jail\n");
        else printf("%d\n",mn);

    }
    return 0;
}
