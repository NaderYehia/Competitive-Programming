#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e5+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m;
int frq[N];
ll mem[N];

ll solve(int i=0){
    if(i>100000) return 0;
    ll &ret=mem[i];
    if(~ret) return mem[i];
    ret=max(solve(i+1),1ll*frq[i]*i+solve(i+2));
    return ret;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d",&n);
    for(int i=0,tmp;i<n;++i)
        scanf("%d",&tmp),frq[tmp]++;
    memset(mem,-1,sizeof mem);
    printf("%lld",solve());
    return 0;
}
