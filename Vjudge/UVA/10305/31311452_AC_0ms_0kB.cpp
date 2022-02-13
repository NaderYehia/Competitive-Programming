#include <bits/stdc++.h>

using namespace std;

const int N=100+10,M=10000+10;

int head[N],to[M],nxt[M],ne;
bool vis[N],cycle;
int v[N],sz;

void addedge(int u,int v){
    to[ne]=v;
    nxt[ne]=head[u];
    head[u]=ne;
    ne++;
}

void init(int n){
    memset(head,-1,n*sizeof head[0]);
    memset(vis,0,n*sizeof vis[0]);
    ne=sz=0;
}

void dfs(int u){
    vis[u]=1;
    for(int ei=head[u];ei!=-1;ei=nxt[ei]){
        int v=to[ei];
        if(!vis[v]){
            dfs(v);
        }
    }
    v[sz++]=u+1;
}

int main()
{

    int n,m;
    while(cin>>n>>m,(n+m)){

        init(n);

        for(int i=0;i<m;++i){
            int u,v;
            cin>>u>>v;
            --u,--v;
            addedge(v,u);
        }

        for(int i=0;i<n;++i){
            if(!vis[i]){
                dfs(i);
            }
        }

        for(int i=0;i<sz;++i){
            cout<<v[i]<<" \n"[i+1==sz];
        }

    }


    return 0;
}
