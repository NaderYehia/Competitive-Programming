#include<bits/stdc++.h>

using namespace std;

int t,k,n,m,cows;
int arr[100006];

bool can(int x){
    long long lastVisited=-1,tmp=0;
    for(int i=0;i<n;++i){
        if(lastVisited<=arr[i]){
            ++tmp;
            lastVisited=arr[i]+x;
        }
    }
    if(cows>tmp)
        return 0;
    return 1;
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
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&cows);
        for(int i=0;i<n;++i)
            scanf("%d",arr+i);
        sort(arr,arr+n);
        printf("%d",bs());
        if(t)
            printf("\n");
    }
	return 0;
}
