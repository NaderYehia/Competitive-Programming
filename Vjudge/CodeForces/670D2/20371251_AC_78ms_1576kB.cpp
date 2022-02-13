#include<bits/stdc++.h>
using namespace std;
long long a0 [(int)1e5+5];
long long a1 [(int)1e5+5];
long long n,k;
bool canWeBake(long long x){
	long long tmp=k;
	for(int i=0;i<n;++i){
		if(a0[i]*x>a1[i]){
			if(tmp<a0[i]*x-a1[i])
				return 0;
			tmp-=a0[i]*x-a1[i];
		}
	}
	return 1;
}
long long binarySearch(){
	long long mid, lo=0,hi=1e10;
	while(hi-lo>0){
		mid=(hi+lo+1)/2;
		if(canWeBake(mid))	lo=mid;
		else hi=mid-1;
	}
	return lo;
}
 
int main(){
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;++i)
		scanf("%lld",&a0[i]);
	for(int i=0;i<n;++i)
		scanf("%lld",&a1[i]);
	printf("%lld",binarySearch());	
}