#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=5e4+10,M=1e9+7,OO=0x3f3f3f3f;
const double eps=1e-6;

ll lcm(ll a,ll b){
    return a/__gcd(a,b)*b;
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    ll n,m;
    while(~scanf("%lld%lld",&n,&m),(n!=1||m!=1)){
        pair<ll,ll> lf,rt,cur;
        if(n<m){
            printf("L");
            rt={1,1};
            lf={0,1};
            cur={1,2};
        }
        else{
            printf("R");
            rt={1,0};
            lf={1,1};
            cur={2,1};
        }
        while(cur.first!=n||cur.second!=m){
            ll denom=lcm(cur.second,m);
            ll numer1=denom/m*n;
            ll numer2=denom/cur.second*cur.first;
            if(numer1>numer2){
                printf("R");
                lf=cur;
                cur.first+=rt.first;
                cur.second+=rt.second;
            }
            else{
                printf("L");
                rt=cur;
                cur.first+=lf.first;
                cur.second+=lf.second;
            }
        }
        puts("");
    }

    return 0;
}
