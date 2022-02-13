#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>v;
int a[N]={},t,n;
bitset<N>isP;
void sieve(){
	isP.set();
	isP[0]=isP[1]=0;
	for(int i=2;i<N;++i)
		if(isP[i])
			for(int j=i*2;j<N;j+=i)
				isP[j]=0,++a[j];
	
}

int main(){
	sieve();
	for(int i=0;i<N;++i)
		if(a[i]>=3)
			v.push_back(i);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%d\n",v[n-1]);
	}
}