#include<bits/stdc++.h>
using namespace std;
const int N=1005;
bitset<N>isP;
int arr[N];
vector<int>v;
void sieve(){
	v.push_back(0);
	v.push_back(1);
	int p=1;
	isP.set();
	isP[0]=0;
	isP[1]=1;
	arr[1]=1;
	for(int i=2;i<=N;++i){
		if(isP[i]){
			v.push_back(i);
			arr[i]=++p;
			for(int j=i*i;j<=N;j+=i)
				isP[j]=0;
			}
			arr[i]=p;
		}
}
int main(){
	sieve();
	int n,c;
	while(scanf("%d %d",&n,&c)==2){
		printf("%d %d:",n,c);
		if(2*c>=arr[n]){
			for(int i=1;i<=arr[n];++i)
				printf(" %d",v[i]);
			puts("\n");
		}
		else if(arr[n]&1){
			int j=arr[n]/2+1;
			for(int i=0,k=j-(c-1);i<(2*c)-1;++i,++k)
				printf(" %d",v[k]);
			puts("\n");
		}
		else {
			int j=arr[n]/2;
			for(int i=0,k=j-(c-1);i<2*c;++i,++k)
				printf(" %d",v[k]);
			puts("\n");
		}
	}
}