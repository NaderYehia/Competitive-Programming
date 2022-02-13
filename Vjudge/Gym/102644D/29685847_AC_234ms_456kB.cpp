#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e3+10,M=1e9+7,OO=0x3f3f3f3f;

typedef vector<vector<int> > vvi;

vvi matrixMul(vvi a,vvi b){
    vvi ret(a.size(),vector<int> (b[0].size(),0));
    for(int i=0;i<a.size();++i){
        for(int j=0;j<b[0].size();++j){
            for(int k=0;k<a[0].size();++k){
                ret[i][j]=(ret[i][j]+(a[i][k]*1ll*b[k][j])%M)%M;
            }
        }
    }
    return ret;
}

vvi matrixPow(vvi x,ll p,int n){
    vvi ret(n,vector<int> (n,0));
    for(int i=0;i<n;++i)
        ret[i][i]=1;
    while(p){
        if(p&1) ret=matrixMul(ret,x);
        x=matrixMul(x,x);
        p>>=1;
    }
    return ret;
}



int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);


    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    vvi cur(n,vector<int> (n,0));
    for(int i=0;i<m;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        --u,--v;
        cur[u][v]=1;
    }

    cur=matrixPow(cur,k,n);

    int ans=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            ans=(ans+cur[i][j])%M;
        }
    }

    printf("%d\n",ans);

    return 0;
}
