#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=2e5+10,M=1e9+7,OO=0x3f3f3f3f;

ll mem[65][65];

ll nCr(int n,int r){
    if(n<r||r<0) return 0;
    if(n==r) return 1;
    ll &ret=mem[n][r];
    if(~ret) return ret;
    return ret=nCr(n-1,r)+nCr(n-1,r-1);
}

ll cntBits(ll x,int k){
    ll cur=0,cnt=0;
    for(int i=0;i<64;++i){
        if((1ll<<i)&x) ++cur;
    }
    if(cur==k) ++cnt;
    for(int i=0;i<64;++i){
        if((1ll<<i)&x){
            --cur;
            cnt+=nCr(i,k-cur);
        }
    }
    return cnt;
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);


    memset(mem,-1,sizeof mem);

    ll m;
    int k;
    scanf("%llu%d",&m,&k);

    ll lo=1,hi=1e18;
    while(lo<hi){
        ll md=lo+(hi-lo)/2;
        if(cntBits(md*2,k)-cntBits(md,k)>=m) hi=md;
        else lo=md+1;
    }

    printf("%llu\n",lo);

    return 0;
}
