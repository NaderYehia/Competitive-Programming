#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e3+10,M=1e3+7,OO=0x3f3f3f3f;



int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int n,d;
    scanf("%d%d",&n,&d);
    vector<int> points(n);
    for(int i=0;i<n;++i)
        scanf("%d",&points[i]);

    sort(points.begin(),points.end());

    ll ans=0;
    for(int i=0;i<n;++i){
        int hi=upper_bound(points.begin(),points.end(),points[i]+d)-points.begin();
        int cnt=hi-i-1;
        ans+=cnt*1ll*(cnt-1)/2;
    }

    printf("%lld\n",ans);

    return 0;
}
