#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+2;
int n,k,m, a[N], b[N];
int mem[N][N];
int WB(int i, int remW){
	if(i==m) return 0;
	if(mem[i][remW] != -1) return mem[i][remW];
	int op1=WB(i+1 , remW);
	int op2=a[i]<=remW ? b[i]+WB(i+1,remW-a[i]) : 0;
	return mem[i][remW] =max(op1 , op2);
}
int p;
int main(){
	scanf("%d" ,&n);
	while(n--){
		scanf("%d %d" ,&k ,&m);
		for(int i=0 ; i<m ; i++) scanf("%d %d" , a+i , b+i);
			memset(mem , -1 , sizeof mem);
			p=WB(0,k);
			printf("Hey stupid robber, you can get %d.\n" , p);
}
}
