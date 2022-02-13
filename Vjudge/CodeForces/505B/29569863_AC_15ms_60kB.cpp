#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e2+10,M=2e9+7,OO=0x3f3f3f3f;

struct dsu{
    vector<int> par;

    void init(int n){
        par.resize(n);
        for(int i=0;i<n;++i)
            par[i]=i;
    }

    int get(int u){
        return par[u]==u?u:par[u]=get(par[u]);
    }

    void join(int u,int v){
        int pu=get(u),pv=get(v);
        if(pu==pv) return;
        par[pu]=pv;
    }

    bool same(int u,int v){
        int pu=get(u),pv=get(v);
        return pu==pv;
    }

};

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);


    int n,m;
    scanf("%d%d",&n,&m);

    vector<dsu> dsus(m);
    for(int i=0;i<m;++i)
        dsus[i].init(n);

    for(int i=0;i<m;++i){
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        --u,--v,--c;
        dsus[c].join(u,v);
    }

    int q;
    scanf("%d",&q);
    while(q--){
        int u,v;
        scanf("%d%d",&u,&v);
        --u,--v;
        int cnt=0;
        for(int i=0;i<m;++i){
            cnt+=dsus[i].same(u,v);
        }
        printf("%d\n",cnt);
    }

    return 0;
}
