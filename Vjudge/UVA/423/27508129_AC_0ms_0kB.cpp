#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e2+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m,q;
vector<pair<int,int> >adj[N];
int dis[N];
int ddd[N];

int toInt(string s){
    int ret=0;
    for(int i=0;s[i];++i)
        ret=ret*10+(s[i]-'0');
    return ret;
}

void dijkstra(int src){
    memset(dis,'?',n*sizeof dis[0]);
    priority_queue<pair<pair<int,int>,int> >pq;
    pq.push(make_pair(make_pair(0,src),0));
    while(pq.size()){
        int u=pq.top().first.second;
        int d=pq.top().first.first;
        int b=pq.top().second;
        pq.pop();
        if(dis[u]!=OO) continue;
        dis[u]=-d;
        ddd[u]=b;
        for(int i=0;i<adj[u].size();++i){
            int v=adj[u][i].first;
            int c=adj[u][i].second;
            if(dis[v]==OO) pq.push(make_pair(make_pair(d-c,v),c));
        }
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("myfile.txt","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        for(int j=0,v;j<i;++j){
            string s;
            cin>>s;
            if(s=="x") continue;
            v=toInt(s);
            adj[i].push_back({j,v});
            adj[j].push_back({i,v});
        }
    }
    dijkstra(0);
    int ans=0;
    for(int i=1;i<n;++i)
        ans=max(ans,dis[i]);
    printf("%d\n",ans);
    return 0;
}
