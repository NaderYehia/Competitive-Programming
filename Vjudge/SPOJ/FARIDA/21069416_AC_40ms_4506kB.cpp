#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int a[N];
long long mem[N];
long long n,t,l;
long long mon(int i){
	if(i>=n)	return 0;
	if(mem[i]!=-1)	return mem[i];
	long long op1=a[i]+mon(i+2);
	long long op2=mon(i+1);
	return mem[i]=max(op1,op2);
}
int main(){
	scanf("%d",&t);
	while(t--){
		memset(mem,-1,sizeof mem);
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%d",a+i);
			printf("Case %d: %lld\n",++l,mon(0));
	}
}