#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e6+10,M=1e9,OO=0x3f3f3f3f;


int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int n;
    scanf("%d",&n);
    vector<int> arr(n);
    int sum=0;
    for(int i=0;i<n;++i)
        scanf("%d",&arr[i]),sum+=arr[i];
    if(sum==0){
        printf("%d\n",sum);
        return 0;
    }

    int zeros=0;
    ll ans=1;
    int i=0;
    while(arr[i]==0) ++i;
    for(;i<n;++i){
        if(arr[i]==0) ++zeros;
        else ans*=(zeros+1),zeros=0;
    }
    printf("%lld\n",ans);

    return 0;
}
