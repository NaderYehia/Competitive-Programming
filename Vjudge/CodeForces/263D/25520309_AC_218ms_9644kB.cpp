#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5,OO=0x3f3f3f3f,M=1e9+7;
int t,n,m,k;
vector<int> adj[N];
int pr[N];
int st,en,deg;
bool vis[N];
vector<int> ans;

void print(int from,int to){
    int idx=0;
    for(int i=0;i<ans.size();++i){
        if(ans[i]==to){
            idx=i;
        }
    }
    printf("%d\n",ans.size()-idx);
    for(int i=idx;i<ans.size();++i)
        printf("%d%c",ans[i]+1," \n"[i+1==ans.size()]);
    exit(0);
}

void dfs(int u,int par){
    vis[u]=1;
    for(int i=0,v;i<adj[u].size();++i){
        v=adj[u][i];
        if(!vis[v]) pr[v]=pr[u]+1,ans.push_back(v),dfs(v,u),ans.pop_back();
        else if(par!=v&&pr[u]-pr[v]>=k) print(u,v);
    }
}


int main() {
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0,u,v;i<m;++i){
        scanf("%d%d",&u,&v);
        --u,--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<n;++i){
        if(!vis[i])
            pr[i]=0,ans.push_back(i),dfs(i,-1),ans.pop_back();
    }
    return 0;
}
