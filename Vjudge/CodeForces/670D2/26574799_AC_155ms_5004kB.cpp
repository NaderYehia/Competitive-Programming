#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e5+5,OO=0x3f3f3f3f;
const double eps=1e-6,pi=3.14159265359;
int t,n,k,m;
int ned[N];
int hav[N];

bool can(ll x){
    ll tmp=k;
    for(int i=0;i<n;++i){
        if(x*ned[i]>hav[i]){
            ll magic=x*ned[i]-hav[i];
            if(tmp>=magic) tmp-=magic;
            else return 0;
        }
    }
    return 1;
}

ll bs(){
    ll lo=0,hi=2e9,mid;
    while(lo<hi){
        mid=lo+(hi-lo+1)/2;
        if(can(mid)) lo=mid;
        else hi=mid-1;
    }
    return lo;
}

int main(){
    //freopen("business.in","r",stdin);
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i)
        scanf("%d",ned+i);
    for(int i=0;i<n;++i)
        scanf("%d",hav+i);
    printf("%lld",bs());
    return 0;
}
