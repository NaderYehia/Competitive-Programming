#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;
int t,n,c;
int arr[N];
int mem[N][5];

int solve(int i,int msk){
    if(i==n)
        return 0;
    if(mem[i][msk]!=-1) return mem[i][msk];
    if(arr[i]==0)
        return 1+solve(i+1,0);
    int op1=solve(i+1,0)+1;
    int op2;
    if(msk==0){
        if(arr[i]==3)
            op2=min(solve(i+1,1),solve(i+1,2));
        else if(arr[i]==1)
            op2=solve(i+1,1);
        else
            op2=solve(i+1,2);
    }
    else if(msk==1){
        if(arr[i]==3)
            op2=solve(i+1,2);
        else if(arr[i]==1)
            op2=10000000000;
        else
            op2=solve(i+1,2);
    }
    else if(msk==2){
        if(arr[i]==3)
            op2=solve(i+1,1);
        else if(arr[i]==1)
            op2=solve(i+1,1);
        else
            op2=10000000000;
    }
    return mem[i][msk]=min(op1,op2);
}

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",arr+i);
    memset(mem,-1,sizeof mem);
    printf("%d",solve(0,0));
    return 0;
}
