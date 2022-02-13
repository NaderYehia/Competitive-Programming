#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e4+10,M=1e5+7,OO=0x3f3f3f3f;

int n,m;
int head[N],to[M],nxt[M],curEdge,deg[N],vis[M],vid;
int path[N],cur;


void init(){
    memset(head,-1,n*sizeof head[0]);
    memset(deg,0,n*sizeof deg[0]);
    ++vid;
    curEdge=0;
    cur=0;
}

void addEdge(int u,int v){
    nxt[curEdge]=head[u];
    head[u]=curEdge;
    to[curEdge]=v;
    curEdge++;
}

void addBiEdge(int u,int v){
    addEdge(u,v);
    addEdge(v,u);
}

void euler(int u){
    for(;~head[u];){
        int e=head[u];
        head[u]=nxt[e];
        int v=to[e];
        euler(v);
        path[cur++]=e;
    }
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    while(~scanf("%d%d",&n,&m),n||m){
        init();
        for(int i=0;i<m;++i){
            int u,v;
            scanf("%d%d",&u,&v);
            addEdge(u,v);
            --deg[u],++deg[v];
        }
        int cnt=0,st=0,ok=1;
        for(int i=0;i<n;++i)
            if(deg[i]==-1) ++cnt,st=i;
            else if(deg[i]!=0&&deg[i]!=1) ok=0;
        euler(st);
        ok&=(cur==m);
        if(!ok||cnt>1){
            printf("Impossible\n");
            continue;
        }
        printf("%d",st);
        for(int i=cur-1;~i;--i)
            printf(" %d",to[path[i]]);
        puts("");
    }

    return 0;
}
