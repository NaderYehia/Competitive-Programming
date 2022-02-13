#include<bits/stdc++.h>
using namespace std;
vector<long long> vc;
long long n,k;
int main(){
	scanf("%lld%lld",&n,&k);
	for(long long i=1;i*i<=n;++i)
		if(n%i==0){
			vc.push_back(i);
			if(i != n/i) {
				vc.push_back(n/i);
			}
		}
	if(vc.size()<k){
		printf("-1");
		return 0;
	}
	sort(vc.begin(),vc.end());
	printf("%lld",vc[k-1]);
}