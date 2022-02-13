#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e4+10,M=2e4+7,OO=0x3f3f3f3f;



int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int n;
    scanf("%d",&n);
    vector<int> arr(n);
    for(int i=0;i<n;++i)
        scanf("%d",&arr[i]);
    sort(arr.rbegin(),arr.rend());
    ll sum=0;
    for(int i=2;i<n;i+=3)
        sum+=arr[i];
    printf("%lld\n",sum);

    return 0;
}
