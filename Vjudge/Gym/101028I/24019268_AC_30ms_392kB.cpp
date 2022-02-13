#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5,M=1e9+7,OO=0x3f3f3f3f;

int t,n,k;
int arr[N];

bool can(int st){
    int tmp=k,lastCovered=0;
    for(int i=0;i<n;++i){
        if(arr[i]>lastCovered){
            if(!tmp)
                return 0;
            --tmp;
            lastCovered=arr[i]+st-1;
        }
    }
    return 1;
}

int bs(){
    int lo=0,hi=1e9+5,mid;
    while(hi-lo>0){
        mid=(lo+hi)/2;
        if(can(mid))
            hi=mid;
        else
            lo=mid+1;
    }
    return lo;
}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;++i)
            scanf("%d",arr+i);
        printf("%d\n",bs());
    }
    return 0;
}
