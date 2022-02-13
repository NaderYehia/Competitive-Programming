#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e5+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int n,m,w[105],v[105],c[N];
ll mem[105][N];

ll solve(int i=0,int remW=m){
    if(i==n) return 0;
    ll &ret=mem[i][remW];
    if(~ret) return ret;
    ret=max(solve(i+1,remW),remW-w[i]>=0?solve(i+1,remW-w[i])+v[i]:(int)-1e9);
    return ret;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
        scanf("%d%d",w+i,v+i);
    memset(mem,-1,sizeof mem);
    printf("%lld",solve());
    return 0;
}
