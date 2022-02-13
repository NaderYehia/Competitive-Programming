#include<bits/stdc++.h>

using namespace std;

const int N=2e3+5;
int t,n,x;
int arr[105];
int mem[105][100005];

int solve(int i,int paid){
    if(paid>100000)
        return 1000000000;
    if(i==n){
        if(paid>=x)
            return (paid-x);
        return 1000000000;
    }
    if(mem[i][paid]!=-1) return mem[i][paid];
    int op1=solve(i+1,paid);
    int op2=solve(i+1,paid+arr[i]);
    return mem[i][paid]=min(op1,op2);
}

int solveAg(int i,int rem){
    if(i==n){
        if(rem==0)
            return 0;
        return 1000000000;
    }
    if(mem[i][rem]!=-1) return mem[i][rem];
    int op1=solveAg(i+1,rem);
    int op2=rem-arr[i]>=0?1+solveAg(i+1,rem-arr[i]):1000000000;
    return mem[i][rem]=min(op1,op2);
}

int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&x,&n);
        for(int i=0;i<n;++i)
            scanf("%d",arr+i);
        memset(mem,-1,sizeof mem);
        int ans=solve(0,0)+x;
        memset(mem,-1,sizeof mem);
        int co=solveAg(0,ans);
        printf("%d %d\n",ans,co);
    }
    return 0;
}
