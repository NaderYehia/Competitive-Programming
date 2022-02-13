#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int N=1e6+10,M=1000000009,OO=0x3f3f3f3f;

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

vvi matrixPow(vvi x,ll p){
    vvi ret={{1,0,0},{0,1,0},{0,0,1}};
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

    int tc=1;
    ll n;
    int m;
    while(~scanf("%lld%d",&n,&m),n||m){
        M=m;
        vvi ans={{0,1,0},{1,1,1},{0,0,1}};

        ans=matrixPow(ans,n);

        ans=matrixMul(ans,{{1},{1},{1}});

        printf("Case %d: %lld %d %d\n",tc++,n,m,ans[0][0]);

    }

    return 0;
}
