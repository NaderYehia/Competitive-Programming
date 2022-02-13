#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=2e3+10,M=1e3+7,OO=0x3f3f3f3f;

ll lcm(ll a,ll b){
    return a/__gcd(a,b)*b;
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int t,tc=1;
    scanf("%d",&t);
    while(t --> 0){
        int n;
        scanf("%d",&n);
        vector<ll> arr(n);
        for(int i=0;i<n;++i)
            scanf("%lld",&arr[i]);

        if(n==1){
            printf("Case %d: %lld/1\n",tc++, arr[0]);
            continue;
        }

        ll g=0;
        for(int i=0;i<n;++i)
            g=__gcd(g,arr[i]);


        ll lcm=1;
        for(int i=0;i<n;++i){
            lcm*=arr[i];
            ll curG=__gcd(lcm,g);
            lcm/=curG;
            g/=curG;
        }


        ll num=lcm*n;
        ll den=0;
        for(int i=0;i<n;++i)
            den+=lcm/arr[i];

        g=__gcd(num,den);
        num/=g;
        den/=g;

        printf("Case %d: %lld/%lld\n",tc++, num,den);

    }



    return 0;
}
