#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e3+5,OO=0x3f3f3f3f;
int t,n,m,k,q;
ll arr[N];

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%lld",arr+i);
        arr[n]=1e18;
        ll total=0;
        int cnt=0;
        for(int i=0;i<n;++i){
            if(total+arr[i]<arr[i+1]){
                total+=arr[i];
                ++cnt;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
