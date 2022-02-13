#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e4+5,OO=0x3f3f3f3f;
const double eps=1e-6,pi=3.14159265359;
int t,n,k,m;
int val[N];
ll mem[N];

ll solve(int idx){
    if(idx>=n)
        return 0;
    ll &ret=mem[idx];
    if(ret!=-1) return ret;
    ret=max(solve(idx+1),solve(idx+2)+val[idx]);
    return ret;
}

int main(){
    //freopen("business.in","r",stdin);
    int tc=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%d",val+i);
        memset(mem,-1,sizeof mem);
        printf("Case %d: %lld\n",tc++,solve(0));
    }
    return 0;
}
