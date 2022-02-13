#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e3+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m,q,k,d;
int dis[155][155];
map<int,int> mp;

int main(){
    //freopen("tree.in","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("myfile.txt","w",stdout);
    int u,v,tc=1;
    while(scanf("%d%d",&u,&v),u+v){
        vector<pair<int,int> >ed;
        ed.push_back({u,v});
        while(scanf("%d%d",&u,&v),u+v) ed.push_back({u,v});
        mp.clear();
        int id=0;
        for(int i=0;i<ed.size();++i){
            int u=ed[i].first,v=ed[i].second;
            if(mp.find(u)==mp.end()) mp[u]=id++;
            if(mp.find(v)==mp.end()) mp[v]=id++;
        }
        n=id;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                dis[i][j]= i==j?0:OO;
            }
        }
        for(int i=0;i<ed.size();++i){
            u=mp[ed[i].first],v=mp[ed[i].second];
            dis[u][v]=min(dis[u][v],1);
        }
        for(int k=0;k<n;++k){
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j){
                    if(dis[i][k]==OO||dis[k][j]==OO) continue;
                    int nd=dis[i][k]+dis[k][j];
                    dis[i][j]=min(dis[i][j],nd);
                }
            }
        }
        int sum=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                sum+=dis[i][j];
            }
        }
        printf("Case %d: average length between pages = %.3f clicks\n",tc++,1.0*sum/(n*n-n));
    }

    return 0;
}
