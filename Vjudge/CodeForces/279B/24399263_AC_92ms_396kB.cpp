#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;
int n,t;
int arr[N];

bool can(int x){
    for(int i=x;i<=n;++i){
        if(arr[i]-arr[i-x]<=t)
            return 1;
    }
    return 0;
}

int bs(){
    int lo=0,hi=1000000009,mid;
    while(lo<hi){
        mid=(lo+hi+1)/2;
        if(can(mid))
            lo=mid;
        else
            hi=mid-1;
    }
    return lo;
}

int main() {
    scanf("%d%d",&n,&t);
    for(int i=1;i<=n;++i)
        scanf("%d",arr+i);
    for(int i=2;i<=n;++i)\
        arr[i]+=arr[i-1];
    printf("%d",bs());
	return 0;
}
