#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e4+10,M=2e4+7,OO=0x3f3f3f3f;



int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int t,tc=1;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        vector<int> arr1(n);
        vector<int> arr2(n);
        for(int i=0;i<n;++i)
            scanf("%d",&arr1[i]);
        for(int i=0;i<n;++i)
            scanf("%d",&arr2[i]);
        sort(arr1.begin(),arr1.end());
        sort(arr2.rbegin(),arr2.rend());
        ll sum=0;
        for(int i=0;i<n;++i)
            sum+=arr1[i]*1ll*arr2[i];
        printf("Case #%d: %lld\n",tc++,sum);
    }

    return 0;
}
