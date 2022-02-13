#include<bits/stdc++.h>

using namespace std;

const int N=2e3+5,OO=0x3f3f3f3f,M=1e9+7;
int t,n,k;

bitset<N>isPrime;
void sieve(){
    isPrime.set();
    for(int i=2;i<=N/i;++i)
        if(isPrime[i])
            for(int j=i*i;j<N;j+=i)
                isPrime[j]=0;
}

vector<int> v;
vector<int>ans;

int main() {
    sieve();
    for(int i=2;i<N;++i)
        if(isPrime[i])
            v.push_back(i);
    for(int i=1;i<v.size();++i)
        if(isPrime[v[i]+v[i-1]+1])
        ans.push_back(v[i]+v[i-1]+1);
    scanf("%d%d",&n,&k);
    if(upper_bound(ans.begin(),ans.end(),n)-ans.begin()>=k)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
