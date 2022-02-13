#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e5+5,M=1<<30,SEGM=4*N,OO=0x3f3f3f3f;
int n;
vector<int> adj[2050];
int vis[2050];

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
    int Offset=1000;
    scanf("%d",&n);
    vector<int>vec;
    for(int i=0;i<n;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        vec.push_back(u+Offset);
        vec.push_back(v);
        adj[u+Offset].push_back(v);
        adj[v].push_back(u+Offset);
    }
    int cmp=0;
    for(int i=0;i<vec.size();++i){
        if(!vis[vec[i]])
            dfs(vec[i]),++cmp;
    }
    printf("%d",cmp-1);
    return 0;
}
