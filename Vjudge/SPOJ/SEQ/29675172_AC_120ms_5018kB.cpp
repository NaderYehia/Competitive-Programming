#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e6+10,M=1e9,OO=0x3f3f3f3f;

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
    vvi ret(d,vector<int> (d,0));
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

    int t;
    scanf("%d",&t);
    while(t--){
        int k;
        scanf("%d",&k);
        vector<int> b(k);
        for(int i=0;i<k;++i)
            scanf("%d",&b[i]);
        vector<int> c(k);
        for(int i=0;i<k;++i)
            scanf("%d",&c[i]);

        int n;
        scanf("%d",&n);

        if(n<=k){
            printf("%d\n",b[n-1]);
            continue;
        }
        --n;
        vvi ans(k,vector<int> (k,0));
        for(int i=0;i<k-1;++i)
            ans[i][i+1]=1;
        for(int i=k-1;~i;--i)
            ans[k-1][i]=c[k-1-i];

        ans=matrixPow(ans,n,k);

        vvi cur(k,vector<int>(1));
        for(int i=0;i<k;++i)
            cur[i][0]=b[i];

        ans=matrixMul(ans,cur);

        printf("%d\n",ans[0][0]);

    }

    return 0;
}
