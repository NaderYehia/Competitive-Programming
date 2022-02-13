#include<bits/stdc++.h>
using namespace std;
const int N=1009;
int n,k,cnt;
vector<int>v;
bitset<N>isP;
void sieve(){
	isP.set();
	for(int i=2;i<=N;++i){
		if(isP[i]){
			v.push_back(i);
			for(int j=i*i;j<=N;j+=i)
				isP[j]=0;
		}
	}
}
int main(){
	sieve();
	scanf("%d%d",&n,&k);
	for(int i=0;i<v.size()-2;++i){
		if(isP[v[i]+v[i+1]+1] && v[i]+v[i+1]+1<=n )
		++cnt;
	}
	if(k>cnt)
		printf("NO");
	else 
		printf("YES");
}