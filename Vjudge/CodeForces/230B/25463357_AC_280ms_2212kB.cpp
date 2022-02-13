#include<bits/stdc++.h>

using namespace std;

const int N=1e6+5,OO=0x3f3f3f3f,M=1e9+7;
int t,n,d;

bitset<N>isPrime;
void sieve(){
    isPrime.set();
    for(int i=2;i<=N/i;++i)
        if(isPrime[i])
            for(int j=i*i;j<N;j+=i)
                isPrime[j]=0;
}

vector<long long>v;

int main() {
    sieve();
    for(int i=2;i<N;++i)
        if(isPrime[i])
            v.push_back(i*1ll*i);
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        long long tmp;
        scanf("%lld",&tmp);
        if(binary_search(v.begin(),v.end(),tmp))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
