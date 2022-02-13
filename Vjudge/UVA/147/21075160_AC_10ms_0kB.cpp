#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
double a;
int x;
int cur[]={5,10,20,50,100,200,500,1000,2000,5000,10000};
int ncur=11;
long long mem[15][N];
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
	while(scanf("%lf",&a)==1){
		if(a==0.00)
			return 0;
		x=(a+0.001)*100;
		printf("%6.2lf%17lld\n",a,solve(0,x));
	}
}