#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=3e3+5,M=1e9+7,OO=0x3f3f3f3f;
int t,n,m,k;
bitset<N> isPrime;
vector<int> primes;

void sieve(){
    isPrime.set();
    isPrime[0]=isPrime[1]=0;
    for(int i=2;i<=N/i;++i){
        if(isPrime[i])
            for(int j=i*i;j<N;j+=i)
                isPrime[j]=0;
    }
    for(int i=0;i<N;++i)
        if(isPrime[i])
            primes.push_back(i);
}

int main(){
    //freopen("myfile.txt","w",stdout);
    sieve();
    scanf("%d",&n);
    int cnt=0;
    for(int i=6;i<=n;++i){
        int tmp=i,j=0,pr=0;
        while(tmp>1){
            if(tmp%primes[j]==0){
                ++pr;
                while(tmp%primes[j]==0)
                    tmp/=primes[j];
            }
            ++j;
        }
        if(pr==2)
            ++cnt;
    }
    printf("%d",cnt);
    return 0;
}
