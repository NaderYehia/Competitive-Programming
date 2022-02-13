#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e6+5,M=2<<30,OO=0x3f3f3f3f;
ll t,n,m,k;

int main(){
    //freopen("myfile.txt","w",stdout);
    while(~scanf("%lld",&n),n){
        n=abs(n);
        ll ans=-1,tmp=n,pd=0;
        for(ll i=2;i<=tmp/i;++i){
            if(tmp%i==0) ++pd;
            while(tmp%i==0){
                ans=max(ans,i);
                tmp/=i;
            }
        }
        if(tmp!=1&&n!=tmp)
            ans=max(ans,tmp),++pd;
        if(pd>1)
            printf("%lld\n",ans);
        else
            printf("-1\n");
    }
    return 0;
}
