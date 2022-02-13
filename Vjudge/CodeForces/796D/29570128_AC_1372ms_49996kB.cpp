#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=3e5+10,M=2e9+7,OO=0x3f3f3f3f;

vector<int> adj[N];

map<pair<int,int>,int> mp;

bool sec[N],vis[N];

int par[N];

set<int> vec;

void bfs(vector<int> &police){
    memset(par,-1,sizeof par);
    queue<int> q;
    for(int i=0;i<police.size();++i){
        q.push(police[i]-1);
        par[police[i]-1]=-2;
    }
    while(q.size()){
        int u=q.front();
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=0;i<adj[u].size();++i){
            int v=adj[u][i];
            if(v==par[u]) continue;
            if(vis[v]){
                if(mp.find({u,v})!=mp.end()) vec.insert(mp[{u,v}]);
                else vec.insert(mp[{v,u}]);
            }
            else{
                if(par[v]==-1) q.push(v),par[v]=u;
            }
        }
    }
}


int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int n,k,d;
    scanf("%d%d%d",&n,&k,&d);

    vector<int> police(k);
    for(int i=0;i<k;++i)
        scanf("%d",&police[i]);

    for(int i=0;i<n-1;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        --u,--v;
        mp[{u,v}]=i+1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(police);

    printf("%d\n",vec.size());
    for(set<int>::iterator it=vec.begin();it!=vec.end();++it)
        printf("%d ",(*it));

    return 0;
}
