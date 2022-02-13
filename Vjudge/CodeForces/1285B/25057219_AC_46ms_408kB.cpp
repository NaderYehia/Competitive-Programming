#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;
int t,n,c;
int arr[N];

long long kadane(int l,int r){
    long long mx=-1000000000,mxhere=0;
    for(int i=l;i<r;++i){
        mxhere+=arr[i];
        mx=max(mxhere,mx);
        if(mxhere<0)
            mxhere=0;
    }
    return mx;
}

int main() {
    scanf("%d",&t);
    while(t--){
        long long sum=0;
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%d",arr+i),sum+=arr[i];
        if(kadane(0,n-1)>=sum||kadane(1,n)>=sum)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
