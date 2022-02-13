#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;
int t,n,a,b,c;
long long mem[N];

long long solve(int rem){
    if(rem==0)
        return 0;
    if(mem[rem]!=-1) return mem[rem];
    long long op1=rem-a>=0?solve(rem-a)+1:-1000000000;
    long long op2=rem-b>=0?solve(rem-b)+1:-1000000000;
    long long op3=rem-c>=0?solve(rem-c)+1:-1000000000;
    return mem[rem]=max(op1,max(op2,op3));
}

int main() {
    scanf("%d%d%d%d",&n,&a,&b,&c);
    memset(mem,-1,sizeof mem);
    printf("%lld",solve(n));
    return 0;
}
