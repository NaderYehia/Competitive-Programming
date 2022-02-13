#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e3+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m;
int p[N],w[N];
int mem[N][50];

int solve(int i,int remW){
    if(i==n) return 0;
    int &ret=mem[i][remW];
    if(~ret) return ret;
    ret=solve(i+1,remW);
    ret=max(ret,remW-w[i]>=0?solve(i+1,remW-w[i])+p[i]:(int)-1e9);
    return ret;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%d%d",p+i,w+i);
        memset(mem,-1,sizeof mem);
        ll ans=0;
        scanf("%d",&m);
        while(m--){
            int x;
            scanf("%d",&x);
            ans+=solve(0,x);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
