#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=2e5+5,M=1e9+7,OO=0x3f3f3f3f;
int t,n,m,k;
int arr[N];

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",arr+i),arr[i]=abs(arr[i]);
    sort(arr,arr+n);
    ll cnt=0;
    for(int i=0;i<n;++i){
        int idx=upper_bound(arr,arr+n,2*arr[i])-arr-1;
        cnt+=idx-i;
    }
    printf("%lld",cnt);
    return 0;
}
