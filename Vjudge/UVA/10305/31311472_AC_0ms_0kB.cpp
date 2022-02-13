#include <bits/stdc++.h>

using namespace std;

const int N=100+10,M=10000+10;

int head[N],to[M],nxt[M],ne;
int v[N],sz;
int in[N];

void addedge(int u,int v){
    to[ne]=v;
    nxt[ne]=head[u];
    head[u]=ne;
    ne++;
}

void init(int n){
    memset(head,-1,n*sizeof head[0]);
    ne=sz=0;
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
            addedge(u,v);
            in[v]++;
        }

        queue<int> q;
        for(int i=0;i<n;++i){
            if(in[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            v[sz++]=u+1;
            for(int ei=head[u];ei!=-1;ei=nxt[ei]){
                int ne=to[ei];
                --in[ne];
                if(in[ne]==0) q.push(ne);
            }
        }

        for(int i=0;i<sz;++i){
            cout<<v[i]<<" \n"[i+1==sz];
        }

    }


    return 0;
}
