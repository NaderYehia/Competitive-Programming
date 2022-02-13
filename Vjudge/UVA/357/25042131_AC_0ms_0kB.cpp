#include<bits/stdc++.h>

using namespace std;

const int N=3e4+5;
int n;
int cur[]={1,5,10,25,50};
long long mem[10][N];

long long solve(int i,int rem){
    if(i==5){
        if(rem==0)
            return 1;
        return 0;
    }
    if(mem[i][rem]!=-1) return mem[i][rem];
    long long op1=solve(i+1,rem);
    long long op2=rem-cur[i]>=0?solve(i,rem-cur[i]):0;
    return mem[i][rem]=op1+op2;
}

int main() {
    memset(mem,-1,sizeof mem);
    while(~scanf("%d",&n)){
        long long ans;
        ans=solve(0,n);
        if(ans==1)
            printf("There is only 1 way to produce %d cents change.\n",n);
        else
            printf("There are %lld ways to produce %d cents change.\n",ans,n);
    }
    return 0;
}
