#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;
const int N=1e5+5,M=1e9+7,OO=0x3f3f3f3f;
int n,m,k,r;
vector<int> adj[N];
vector<int>Radj[N];
int vis[N],vid;
int stk[N],sz;
int ids[N];

void dfs(int u){
    vis[u]=vid;
    for(int i=0;i<adj[u].size();++i){
        int v=adj[u][i];
        if(vis[v]!=vid)
            dfs(v);
    }
    stk[sz++]=u;
}

void dfs2(int u,int id){
    vis[u]=vid;
    ids[u]=id;
    for(int i=0;i<Radj[u].size();++i){
        int v=Radj[u][i];
        if(vis[v]!=vid)
            dfs2(v,id);
    }
}

int notSrc[N],notSnk[N],cmpCnt;
void kosoraju(){
    ++vid;
    for(int i=1;i<=n;++i){
        if(vis[i]!=vid){
            dfs(i);
        }
    }
    ++vid;
    cmpCnt=0;
    while(sz--){
        if(vis[stk[sz]]!=vid)
            dfs2(stk[sz],cmpCnt++);
    }
    for(int i=1;i<=n;++i){
        for(int j=0;j<adj[i].size();++j){
            int v=adj[i][j];
            if(ids[i]==ids[v]) continue;
            notSrc[ids[v]]=vid;
            notSnk[ids[i]]=vid;
        }
    }
}

int main(){
    //freopen("input.in","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("myfile.txt","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        while(~scanf("%d",&m),m){
            adj[i].push_back(m);
            Radj[m].push_back(i);
        }
    }

    kosoraju();

    int Srcs=cmpCnt-count(notSrc,notSrc+cmpCnt,vid);
    int Snks=cmpCnt-count(notSnk,notSnk+cmpCnt,vid);
    printf("%d\n%d\n",Srcs,cmpCnt==1?0:max(Srcs,Snks));
    return 0;
}
