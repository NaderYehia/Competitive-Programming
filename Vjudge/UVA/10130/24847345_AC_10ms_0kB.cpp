#include<bits/stdc++.h>

using namespace std;

const int N=2e3+5;
int t,n,m;
int p[1005];
int w[1005];
int mem[1005][100];

int solve(int i,int rem){
    if(i==n) return 0;
    if(mem[i][rem]!=-1) return mem[i][rem];
    return mem[i][rem]=max(solve(i+1,rem),rem-w[i]>=0?p[i]+solve(i+1,rem-w[i]):-1000000000);
}

int main() {
    scanf("%d",&t);
    while(t--){
        memset(mem,-1,sizeof mem);
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%d%d",p+i,w+i);
        scanf("%d",&m);
        int sum=0;
        while(m--){
            int wt;
            scanf("%d",&wt);
            sum+=solve(0,wt);
        }
        printf("%d\n",sum);
    }
    return 0;
}
