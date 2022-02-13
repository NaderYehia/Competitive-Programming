#include<bits/stdc++.h>

using namespace std;

const int N=1e3+5;
int t,n,m,W;
int p[N],w[N];
int mem[N][50];

int solve(int i,int rem){
    if(i==n)
        return 0;
    if(mem[i][rem]!=-1) return mem[i][rem];
    int op1=solve(i+1,rem);
    int op2=rem-w[i]>=0?p[i]+solve(i+1,rem-w[i]):-1000000000;
    return mem[i][rem]=max(op1,op2);
}

int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%d%d",p+i,w+i);
        memset(mem,-1,sizeof mem);
        scanf("%d",&m);
        int sum=0;
        while(m--){
            scanf("%d",&W);
            sum+=solve(0,W);
        }
        printf("%d\n",sum);
    }
    return 0;
}
