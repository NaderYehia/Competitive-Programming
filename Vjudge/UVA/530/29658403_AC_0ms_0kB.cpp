#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e6+10,M=1e3+7,OO=0x3f3f3f3f;

ll mem[2];


int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);



    int n,m;
    while(~scanf("%d%d",&n,&m),n||m){
        m=max(m,n-m);
        mem[m&1]=1;
        for(int i=m+1;i<=n;++i){
            ll g=__gcd(ll(i-m),mem[(i-1)&1]);
            ll temp=(i-m);
            ll temp1=mem[(i-1)&1];
            temp/=g;
            temp1/=g;
            mem[i&1]=temp1*i/(temp);
        }
        printf("%lld\n",mem[n&1]);
    }


    return 0;
}
