#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=2e5+5,M=1e9+7,OO=0x3f3f3f3f;
const double eps=1e-6,pi=acos(-1);
int t,n,m,k;
ll arr[N];

bool can(ll d){
    ll prv=-2e9,sta=3;
    for(int i=0;i<n;++i){
        if(arr[i]>prv){
            --sta;
            prv=arr[i]+2*d;
        }
    }
    return sta>=0;
}

ll bs(){
    ll lo=0,hi=2e9,mid;
    while(lo<hi){
        mid=lo+(hi-lo)/2;
        if(can(mid)) hi=mid;
        else lo=mid+1;
    }
    return lo;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%lld",arr+i),arr[i]*=2;
    sort(arr,arr+n);
    ll ans=bs();
    printf("%.6f\n",(double)ans/2);
    ll prv=-2e9,sta=3;
    for(int i=0;i<n&&sta;++i){
        if(arr[i]>prv){
            --sta;
            prv=arr[i]+2*ans;
            printf("%.6f ",((double)arr[i]+ans)/2);
        }
    }
    while(sta--){
        printf("%.6f ",(double)arr[n-1]/2);
    }
    return 0;
}
