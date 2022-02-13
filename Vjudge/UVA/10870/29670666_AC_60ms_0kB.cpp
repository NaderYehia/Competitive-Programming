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

vvi matrixPow(vvi x,ll p,int d){
    vvi ret(d,vector<int>(d,0));
    for(int i=0;i<d;++i)
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

    int d,n,m;
    while(~scanf("%d%d%d",&d,&n,&m),d||n||m){
        M=m;
        vvi ans(d,vector<int>(d,0));
        for(int i=0;i<d-1;++i)
            ans[i][i+1]=1;

        for(int i=d-1;~i;--i)
            scanf("%d",&ans[d-1][i]);

        vvi fi(d,vector<int>(1));

        for(int i=0;i<d;++i)
            scanf("%d",&fi[i][0]);

        ans=matrixPow(ans,n-1,d);

        ans=matrixMul(ans,fi);

        printf("%d\n",ans[0][0]);

    }

    return 0;
}
