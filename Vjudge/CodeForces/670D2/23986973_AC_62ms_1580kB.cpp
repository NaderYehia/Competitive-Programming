#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5,M=1e9+7,OO=0x3f3f3f3f;

long long n,k;
long long a[N];
long long b[N];

bool canWeBake(long long cookies){
    long long po=k;
    for(int i=0;i<n;++i){
        if(a[i]*1ll*cookies>b[i]){
            if(po>=a[i]*1ll*cookies-b[i])
                po-=a[i]*1ll*cookies-b[i];
            else
                return 0;
        }
    }
    return 1;
}

long long bs(){
    long long lo=0,hi=2e9,mid;
    while(hi-lo>0){
        mid=(lo+hi+1)/2;
        if(canWeBake(mid))
            lo=mid;
        else
            hi=mid-1;
    }
    return lo;
}

int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i)
        scanf("%d",a+i);
    for(int i=0;i<n;++i)
        scanf("%d",b+i);
    printf("%d",bs());
    return 0;
}
