#include<bits/stdc++.h>
using namespace std;
int t,n,c;
int a[(int)1e5+5];
bool canThisLen(int l){
	int tmp=c,lastcowpos=0;
	for(int i=0;i<n;++i){
		if(lastcowpos<a[i]){
			lastcowpos=a[i]+l-1;
			tmp--;
		}
}
	if(tmp>0)
		return 0;
		return 1;
}
int binarySearch(){
	int mid,lo=1,hi=1e9;
	while(hi-lo>0){
		mid=(lo+hi+1)/2;
		if(canThisLen(mid))		lo=mid;
		else hi=mid-1;
	}
	return lo;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&c);
		for(int i=0;i<n;++i)	scanf("%d",&a[i]);
		sort(a,a+n);
		printf("%d\n",binarySearch());
	}
}