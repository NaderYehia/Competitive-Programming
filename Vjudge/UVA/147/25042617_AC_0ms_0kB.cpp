#include<bits/stdc++.h>

using namespace std;

const int N=3e4+5;
int n,x,y;
int cur[]={5,10,20,50,100,200,500,1000,2000,5000,10000};
long long mem[15][N];

long long solve(int i,int rem){
    if(i==11){
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
    while(~scanf("%d.%d",&x,&y),(x*100+y)){
        n=x*100+y;
        long long ans;
        ans=solve(0,n);
        printf("%3d.%.2d%17lld\n",x,y,ans);
    }
    return 0;
}
