#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e2+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m,q;
map<string,int> mp;
int dis[N];
bool inq[N];
vector<pair<int,int> > adj[N];

void bellman(int op){
    memset(dis,OO,sizeof dis);
    queue<int> q;
    q.push(0);
    dis[0]=0;
    ++op;
    while(op--){
        int sz=q.size();
        vector<pair<int,int> >changes;
        while(sz--){
            int u=q.front();
            q.pop();
            for(int i=0;i<adj[u].size();++i){
                int v=adj[u][i].first;
                int c=adj[u][i].second;
                if(dis[v]>dis[u]+c){
                    changes.push_back({v,dis[u]+c});
                    q.push(v);
                }
            }
        }
        for(int i=0;i<changes.size();++i)
            dis[changes[i].first]=min(dis[changes[i].first],changes[i].second);
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("myfile.txt","w",stdout);
    int tc=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        mp.clear();
        for(int i=0;i<n;++i)
            adj[i].clear();
        for(int i=0;i<n;++i){
            string s;cin>>s;
            mp[s]=i;
        }
        scanf("%d",&m);
        for(int i=0;i<m;++i){
            string s1,s2;int c;
            cin>>s1>>s2>>c;
            adj[mp[s1]].push_back({mp[s2],c});
        }
        printf("Scenario #%d\n",tc++);
        scanf("%d",&q);
        while(q--){
            int op;
            scanf("%d",&op);
            bellman(op);
            if(dis[n-1]==OO) printf("No satisfactory flights\n");
            else printf("Total cost of flight(s) is $%d\n",dis[n-1]);
        }
        if(t) printf("\n");
    }
    return 0;
}
