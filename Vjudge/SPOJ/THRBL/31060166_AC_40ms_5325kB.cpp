#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;



int main(){
	
	int n,q;
	scanf("%d%d",&n,&q);
	vector<int> arr(n);
	for(int i=0;i<n;++i)
		scanf("%d",&arr[i]);
	
	vector<int>rtl(n);
	stack<int> mono;
	for(int i=n-1;~i;--i){
		while(mono.size()&&arr[mono.top()]<arr[i]) mono.pop();
		if(mono.empty()) rtl[i]=n;
		else rtl[i]=mono.top();
		mono.push(i);
	}

	int cnt=0;
	while(q--){
		int a,b;
		scanf("%d%d",&a,&b);
		--a,--b;
		if(rtl[a]>=b) ++cnt;
	}
	
	printf("%d\n",cnt);
	
	return 0;
}