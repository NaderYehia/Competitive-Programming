#include<bits/stdc++.h>

using namespace std;

const int N=2e3+5,OO=0x3f3f3f3f,M=1e9+7;
long long t,n,k;
vector<long long> v;

int main() {
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n/i;++i){
        if(n%i==0){
            v.push_back(i);
            if(n/i!=i)
                v.push_back(n/i);
        }
    }
    sort(v.begin(),v.end());
    if(k>v.size()){
        printf("-1");
        return 0;
    }
    cout<<v[k-1];
    return 0;
}
