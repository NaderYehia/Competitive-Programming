#include<bits/stdc++.h>
using namespace std;
int cur[]={1,5,10,25,50};
int ncur=5;
long long a;
long long mem[7][100000];
long long solve(int i,int rem){
	if(i==ncur)		return 0;
	if(rem==0)		return 1;
	if(mem[i][rem]!=-1)		return mem[i][rem];
	long long op1=solve(i+1,rem);
	long long op2=rem>=cur[i]?solve(i,rem-cur[i]):0;
	return mem[i][rem]=op1+op2;
}
int main(){
	memset(mem,-1,sizeof mem);
	while(~scanf("%lld",&a))
		printf("%lld\n",solve(0,a));
	
}