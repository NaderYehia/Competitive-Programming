#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e2+10,M=2e9+7,OO=0x3f3f3f3f;

int n;
vector<int> adj[N];
int dis[N];

void go(int s){
    memset(dis,-1,(n+1)*sizeof dis[0]);
    queue<int> q;
    dis[s]=0;
    q.push(s);
    while(q.size()){
        int u=q.front();
        q.pop();
        for(int i=0;i<adj[u].size();++i){
            int v=adj[u][i];
            if(dis[u]+1>dis[v]){
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int tc=1;
    while(~scanf("%d",&n),n){
        for(int i=0;i<=n;++i)
            adj[i].clear();
        int s;
        scanf("%d",&s);
        int u,v;
        while(~scanf("%d%d",&u,&v),u||v){
            adj[u].push_back(v);
        }
        go(s);
        int mx=0,id=s;
        for(int i=1;i<=n;++i){
            if(dis[i]>mx){
                mx=dis[i];
                id=i;
            }
        }
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",tc++,s,mx,id);
    }


    return 0;
}
