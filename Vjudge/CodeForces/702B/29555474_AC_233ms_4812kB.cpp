#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=5e2+10,M=2e9+7,OO=0x3f3f3f3f;



int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    map<int,int> mp;
    int n;
    scanf("%d",&n);
    ll cnt=0;
    while(n--){
        int x;
        scanf("%d",&x);
        for(ll i=1;i<M;i*=2){
            if(mp.find(i-x)==mp.end()) continue;
            cnt+=mp[i-x];
        }
        ++mp[x];
    }
    printf("%lld\n",cnt);

    return 0;
}
