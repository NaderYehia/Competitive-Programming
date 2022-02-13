#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;
int q,n,b;
int arr[200];
int odd[200];
int evn[200];
int mem[200][200];

int solve(int i,int rem){
    if(i==n-1)
        return 0;
    if(mem[i][rem]!=-1) return mem[i][rem];
    int ret;
    if(odd[i]==evn[i]){
        int op1=solve(i+2,rem);
        int op2=abs(arr[i+1]-arr[i])<=rem?1+solve(i+2,rem-abs(arr[i+1]-arr[i])):-1000000000;
        ret=max(op1,op2);
    }
    else{
        ret=solve(i+2,rem);
    }
    return mem[i][rem]=ret;
}

int main() {
    scanf("%d%d",&n,&b);
    for(int i=0;i<n;++i){
        scanf("%d",arr+i);
        if(arr[i]&1)
            ++odd[i];
        else
            ++evn[i];
        if(i>0){
            odd[i]+=odd[i-1];
            evn[i]+=evn[i-1];
        }
    }
    memset(mem,-1,sizeof mem);
    printf("%d",solve(1,b));
    return 0;
}
