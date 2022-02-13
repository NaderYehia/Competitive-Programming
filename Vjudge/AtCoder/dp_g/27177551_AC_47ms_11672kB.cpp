#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e5+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m;
vector<int> adj[N];
int mem[N];

int getMax(int u){
    int &ret=mem[u];
    if(~ret) return ret;
    ret=0;
    for(int i=0,v;i<adj[u].size();++i){
        v=adj[u][i];
        ret=max(ret,getMax(v)+1);
    }
    return ret;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0,u,v;i<m;++i){
        scanf("%d%d",&u,&v);
        adj[--u].push_back(--v);
    }
    memset(mem,-1,sizeof mem);
    int ans=0;
    for(int i=0;i<n;++i)
        ans=max(ans,getMax(i));
    printf("%d",ans);
    return 0;
}
