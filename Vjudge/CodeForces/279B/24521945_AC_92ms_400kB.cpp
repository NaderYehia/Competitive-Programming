#include<bits/stdc++.h>

using namespace std;

int t,k,n,m,cows;
int arr[100006];

bool can(int x){
    for(int i=x;i<=n;++i){
        if(arr[i]-arr[i-x]<=m)
            return 1;
    }
    return 0;
}

int bs(){
    int lo=0,hi=1000000000,mid;
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
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%d",arr+i);
    for(int i=2;i<=n;++i)
        arr[i]+=arr[i-1];
    printf("%d",bs());
	return 0;
}
