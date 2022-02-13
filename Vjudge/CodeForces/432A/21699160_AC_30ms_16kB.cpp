#include<bits/stdc++.h>
using namespace std;
int n,k,cnt;
int arr[2005];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;++i)	
		scanf("%d",arr+i);
	for(int i=0;i<n;++i)
		if(5-arr[i]>=k)
			++cnt;
	cout<<cnt/3;
}
