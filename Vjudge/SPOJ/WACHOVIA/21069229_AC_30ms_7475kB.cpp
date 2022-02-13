#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,k,t,W[N],P[N];
int mem [N][N];
int rob(int i,int remW){
	if(i==n)	return 0;
	if(mem[i][remW]!=-1)	return mem[i][remW];
	int op1=remW>=W[i]? rob(i+1,remW-W[i])+P[i]:0;
	int op2=rob(i+1,remW);
	return mem[i][remW]=max(op1,op2);
}
int main(){
	scanf("%d",&t);
	while(t--){
	memset(mem,-1,sizeof mem);
	scanf("%d%d",&k,&n);
	for(int i=0;i<n;++i)
		scanf("%d%d",&W[i],&P[i]);
	printf("Hey stupid robber, you can get %d.\n",rob(0,k));
}
}