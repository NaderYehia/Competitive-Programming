#include<bits/stdc++.h>

using namespace std;

int mem[100005];
int M=1000000007;
int t,k;

int solve(int n){
    if(mem[n]!=-1) return mem[n];
    return mem[n]=(solve(n-1)%M+(n-k>=0?solve(n-k):0)%M)%M;
}

int main() {
    scanf("%d%d",&t,&k);
    memset(mem,-1,sizeof mem);
    mem[0]=1;
    solve(100000);
    for(int i=1;i<100003;++i)
        mem[i]=(mem[i]+mem[i-1])%M;
    while(t--){
        int a,b;scanf("%d%d",&a,&b);
        printf("%d\n",(mem[b]-mem[a-1]+M)%M);
    }
	return 0;
}
