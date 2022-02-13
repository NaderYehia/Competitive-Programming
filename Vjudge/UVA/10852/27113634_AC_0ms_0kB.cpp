#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e4+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int n;
bitset<N>isPrime;
vector<int>primes;

void sieve(){
    isPrime.set();
    isPrime[0]=isPrime[1]=0;
    for(int i=2;i<N;++i){
        if(isPrime[i]){
            primes.push_back(i);
            for(int j=i*i;j<N;j+=i)
                isPrime[j]=0;
        }
    }
}

int main(){
    //freopen("myfile.txt","w",stdout);
    sieve();
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int idx=upper_bound(primes.begin(),primes.end(),n/2)-primes.begin();
        printf("%d\n",primes[idx]);
    }
    return 0;
}
