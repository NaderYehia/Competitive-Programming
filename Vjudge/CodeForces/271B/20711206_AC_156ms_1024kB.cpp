#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
bitset<N>isP;
void sieve(){
	isP.set();
	isP[0]=isP[1]=0;
	for(int i=2;i<=N/i;++i)
		if(isP[i])
			for(int j=i*i;j<=N;j+=i)
				isP[j]=0;
}
int n,m,cnt,tmp,a[505][505];
int main(){
	int mn=2147483600;
	sieve();
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			scanf("%d",&a[i][j]);
	for(int i=0;i<n;++i){
		cnt=0;
		for(int j=0;j<m;++j){
			tmp=a[i][j];
		while(!isP[tmp]){
				++cnt;
				++tmp;
			}
		}
		mn=min(mn,cnt);
	}
	for(int i=0;i<m;++i){
		cnt=0;
		for(int j=0;j<n;++j){
			tmp=a[j][i];
			while(!isP[tmp]){
				++cnt;
				++tmp;
			}
		}
		mn=min(mn,cnt);
	}
	printf("%d",mn);
}