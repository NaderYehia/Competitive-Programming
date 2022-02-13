#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e3+10,M=2e4+7,OO=0x3f3f3f3f;
const double eps=1e-6;

int head[N],nxt[M],to[M],ne,res[M],sz,deg[N];

void init(){
    memset(head,-1,sizeof head);
    ne=sz=0;
}

void addEdge(int u,int v){
    to[ne]=v;
    nxt[ne]=head[u];
    head[u]=ne++;
}

void euler(int u){
    for(int &e=head[u];~e;){
        int x=e;
        e=nxt[e];
        int v=to[x];
        euler(v);
        res[sz++]=x;
    }
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    vector<pair<int,int> > ed;
    init();
    int n,m;
    scanf("%d",&n);
    int st;
    for(int i=0;i<n;++i){
        scanf("%d",&m);
        int u;
        scanf("%d",&u);
        st=u;
        for(int j=0;j<m;++j){
            int v;
            scanf("%d",&v);
            addEdge(u,v);
            ed.push_back({u,v});
            deg[u]++,deg[v]--;
            u=v;
        }
    }

    bool ok=1;
    for(int i=1;i<=1000;++i)
        if(deg[i]) ok=0;

    euler(st);
    ok&=(sz==ed.size());

    if(!ok){
        puts("0");
    }
    else{
        printf("%d",sz);
        for(int i=sz-1;~i;--i)
            printf(" %d",ed[res[i]].first);
        printf(" %d",ed[res[0]].second);
    }

    return 0;
}
