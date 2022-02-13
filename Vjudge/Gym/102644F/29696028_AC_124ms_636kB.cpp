#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e3+10,M=(1ll<<32),OO=0x3f3f3f3f;

const ll INF=2e18;

typedef vector<vector<ll> > vvi;

vvi matrixMul(vvi a,vvi b,int n){
    vvi ret(n,vector<ll> (n,INF));
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            for(int k=0;k<n;++k){
                if(a[i][k]==INF||b[k][j]==INF) continue;
                ret[i][j]=min(ret[i][j],a[i][k]+b[k][j]);
            }
        }
    }
    return ret;
}

vvi matrixPow(vvi x,int p,int n){
    vvi ret(n,vector<ll> (n,0));
    while(p){
        if(p&1) ret=matrixMul(ret,x,n);
        x=matrixMul(x,x,n);
        p>>=1;
    }
    return ret;
}


int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);


    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);

    vvi cur(n,vector<ll>(n,INF));
    for(int i=0;i<m;++i){
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        --u,--v;
        cur[u][v]=c;
    }

    cur=matrixPow(cur,k,n);

    ll ans=INF;
    bool neg=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(i==j&&cur[i][j]<0) neg=1;
            ans=min(ans,cur[i][j]);
        }
    }

    if(ans==INF) printf("IMPOSSIBLE");
    else printf("%lld\n",ans);

    return 0;
}
