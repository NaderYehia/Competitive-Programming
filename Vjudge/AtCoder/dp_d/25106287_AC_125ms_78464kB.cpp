#include<bits/stdc++.h>

using namespace std;

int n,W;
int w[100001],v[100001];
long long mem[100][100001];

long long solve(int i,int rem){
    if(i==n)
        return 0;
    if(mem[i][rem]!=-1) return mem[i][rem];
    return mem[i][rem]=max(solve(i+1,rem),rem-w[i]>=0?v[i]+solve(i+1,rem-w[i]):-1000000000);
}

int main() {
    scanf("%d%d",&n,&W);
    for(int i=0;i<n;++i)
        scanf("%d%d",w+i,v+i);
    memset(mem,-1,sizeof mem);
    printf("%lld",solve(0,W));
    return 0;
}
