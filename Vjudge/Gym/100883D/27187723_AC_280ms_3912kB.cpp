#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e6+5,M=1e8,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m,k;
int arr[N];

bool can(ll x){
    int l=0,tmpk=k,mxt=0;
    for(int i=0;i<n;++i){
        if(arr[i]>x) return 0;
        if(tmpk<0) return 0;
        mxt=max(mxt,arr[i]);
        if((i-l+1)*1ll*mxt>x){
            --tmpk;
            l=i;
            mxt=arr[i];
        }
    }
    return tmpk>0;
}


ll bs(){
    ll lo=0,hi=1e12,md;
    while(lo<hi){
        md=lo+(hi-lo)/2;
        if(can(md)) hi=md;
        else lo=md+1;
    }
    return lo;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;++i)
            scanf("%d",arr+i);
        printf("%lld\n",bs());
    }
    return 0;
}
