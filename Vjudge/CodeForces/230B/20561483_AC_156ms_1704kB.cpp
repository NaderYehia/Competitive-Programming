#include<bits/stdc++.h>
using namespace std;
int t;
const long long N=1e6+5;
bitset<N> isP;
void sieve(){
	isP.set();
	isP[0]=isP[1]=0;
	for(long long p = 2 ; p <= N/p ; ++p)
            if(isP[p])
                for(long long m = p*p ; m <  N; m += p)
                    isP[m] = 0;
}
int main(){
	sieve();
	vector<long long> tp;
	for(long long i=2;i<=N;++i){
		if(isP[i])
			tp.push_back(i*i);
	}
	scanf("%d",&t);
	while(t--){
		long long n;
		scanf("%lld",&n);
		if(binary_search(tp.begin(),tp.end(),n))
			puts("YES");
		else 
			puts("NO");
	}
}