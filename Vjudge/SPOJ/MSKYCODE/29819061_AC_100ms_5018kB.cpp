#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e4+10,M=10000007,OO=0x3f3f3f3f;
const double eps=1e-9;

vector<int> primes;
bitset<N> isPrime;
void sieve(){
    isPrime.set();
    isPrime[0]=isPrime[1]=0;
    for(int i=2;i<=N/i;++i){
        if(isPrime[i]){
            for(int j=i*i;j<N;j+=i)
                isPrime[j]=0;
        }
    }
    for(int i=2;i<N;++i)
        if(isPrime[i]) primes.push_back(i);
}

int n;
int arr[N];
int cnt[N];
ll ans;

void brrr(int i,int tkn,int s){
    if(i>=primes.size()) return;
    if(s>=N) return;
    if(s>1&&cnt[s]<4) return;
    ll cur=1ll*cnt[s]*(cnt[s]-1)*(cnt[s]-2)*(cnt[s]-3)/2/3/4;
    if(tkn&1) ans-=cur;
    else ans+=cur;
    for(int j=i;j<primes.size();++j)
        brrr(j+1,tkn+1,s*primes[j]);
}

void go(){
    memset(cnt,0,sizeof cnt);
    for(int i=0;i<n;++i){
        for(int j=1;j*j<=arr[i];++j){
            if(arr[i]%j==0){
                cnt[j]++;
                if(arr[i]/j!=j) cnt[arr[i]/j]++;
            }
        }
    }
    cnt[1]=0;
    brrr(0,0,1);
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    sieve();

    while(~scanf("%d",&n)){
        for(int i=0;i<n;++i)
            scanf("%d",arr+i);
        ans=1ll*n*(n-1)*(n-2)*(n-3)/2/3/4;
        go();
        printf("%lld\n",ans);
    }

    return 0;
}
