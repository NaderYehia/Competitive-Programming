#include<bits/stdc++.h>

using namespace std;

const int N=3e3+5,OO=0x3f3f3f3f,M=1e9+7;
int t,n,k;

bitset<N>isPrime;
void sieve(){
    isPrime.set();
    for(int i=2;i<=N/i;++i)
        if(isPrime[i])
            for(int j=i*i;j<N;j+=i)
                isPrime[j]=0;
}

bool two(int n){
    set<int>ans;
    for(int i=2;i<=n/i;++i){
        while(n%i==0)
            ans.insert(i),n/=i;
    }
    if(n!=1)
        ans.insert(n);
    return ans.size()==2;
}

int main() {
    sieve();
    scanf("%d",&n);
    int ans=0;
    for(int i=1;i<=n;++i){
        if(two(i))
            ++ans;
    }
    cout<<ans;
    return 0;
}
