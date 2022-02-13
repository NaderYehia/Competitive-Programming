#include<bits/stdc++.h>

using namespace std;

const int N = 1e6+6,M=1e9+7,OO=0x3f3f3f3f;

long long n,m,k;
bitset<N>isPrime;

void sieve(){
    isPrime.set();
    isPrime[0]=isPrime[1]=0;
    for(int i=2;i<=N/i;++i)
        if(isPrime[i])
            for(int j=i*i;j<=N;j+=i)
                isPrime[j]=0;
}

int main(){
    sieve();
    scanf("%lld",&n);
    while(n--){
        scanf("%lld",&m);
        long long res=sqrt(m);
        if(res*1ll*res==m&&isPrime[res])
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
