#include<bits/stdc++.h>
using namespace std;
int t,n,k;
int a[(int)1e5+5];
bool canWeCover(int x){
	int lastcovered=0,tmp=k;
	for(int i=0;i<n;++i){
		if(a[i]>lastcovered){
			lastcovered=a[i]+x-1;
			tmp--;
		}
	}
		if(tmp<0)
			return 0;
		else	
			return 1;
	
}
int binarySearch(){
	int mid,lo=1,hi=1e9;
	while(hi-lo>0){
		mid=(lo+hi)/2;
		if(canWeCover(mid)) 	hi=mid;
		else lo=mid+1;
	}
	return lo;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&k);
		for(int i=0;i<n;++i)	scanf("%d",&a[i]);
		printf("%d\n",binarySearch());
	}
}