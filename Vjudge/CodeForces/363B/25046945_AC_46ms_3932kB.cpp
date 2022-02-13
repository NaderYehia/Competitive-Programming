#include<bits/stdc++.h>

using namespace std;

const int N=1e6+5;
int t,n,k;
int arr[N];

int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)
        scanf("%d",arr+i);
    for(int i=2;i<=n;++i)
        arr[i]+=arr[i-1];
    int mn=1000000000,idx;
    for(int i=k;i<=n;++i)
        if(mn>arr[i]-arr[i-k])
            mn=arr[i]-arr[i-k],idx=i;
    printf("%d",idx-k+1);
    return 0;
}
