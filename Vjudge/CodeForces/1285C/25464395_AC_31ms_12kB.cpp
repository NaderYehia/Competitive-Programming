#include<bits/stdc++.h>

using namespace std;

const int N=1e4+5,OO=0x3f3f3f3f,M=1e9+7;
int t,k;
long long n;
vector<pair<long long,long long> > v;

int main() {
    scanf("%lld",&n);
    long long tmp=n;
    for(int i=2;i<=n/i;++i){
        int pow=0;
        while(n%i==0){
            n/=i,++pow;
        }
        if(pow)
            v.push_back({i,pow});
    }
    if(n!=1){
        v.push_back({n,1});
    }
    long long mn=100000000000000,ft=1,st=1;
    for(int i=0;i<(1<<v.size());++i){
        int msk=i;
        long long fst=1,scd=1;
        for(int j=0;j<v.size();++j){
            if((1<<j)&msk)
                fst*=(long long)pow(v[j].first,v[j].second);
        }
        scd=tmp/fst;
        if(mn>max(fst,scd)){
            mn=max(fst,scd);
            ft=fst,st=scd;
        }
    }
    cout<<ft<<" "<<st;
    return 0;
}
