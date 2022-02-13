#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e5+5,M=1<<30,SEGM=4*N,OO=0x3f3f3f3f;
int n;
vector<int> adj[250];
int vis[260];

void dfs(int u){
    vis[u]=1;
    for(int i=0,v;i<adj[u].size();++i){
        v=adj[u][i];
        if(!vis[v])
            dfs(v);
    }
}

int main(){
    //freopen("myfile.txt","w",stdout);
    int m,empOffset=101,mno,nonz=0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        scanf("%d",&mno);
        if(mno) nonz=1;
        for(int j=0,v;j<mno;++j){
            scanf("%d",&v);
            adj[empOffset+i].push_back(v);
            adj[v].push_back(empOffset+i);
        }
    }
    int cmp=0;
    for(int i=empOffset;i<empOffset+n;++i){
        if(!vis[i])
            dfs(i),++cmp;
    }
    printf("%d",cmp-nonz);
    return 0;
}
