#include<bits/stdc++.h>

using namespace std;

const int N = 1e6+6,M=1e9+7,OO=0x3f3f3f3f;

long long sum;
int n,m,k;
long long arr[N],cum[N];

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",arr+i);
    sort(arr,arr+n);
    cum[n-1]=arr[n-1];
    for(int i=n-2;i>-1;--i)
        cum[i]=arr[i]+cum[i+1];
    for(int i=0;i<n-1;++i)
        sum+=cum[i]+arr[i];
    sum+=arr[n-1];
    printf("%lld",sum);
    return 0;
}
