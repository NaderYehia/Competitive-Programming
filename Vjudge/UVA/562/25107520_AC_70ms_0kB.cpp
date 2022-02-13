#include<bits/stdc++.h>

using namespace std;

const int N=1e5;
int t,n;
int arr[105];
int mem[105][50005];

int solve(int i,int rem){
    if(i==n){
        return rem;
    }
    if(mem[i][rem]!=-1) return mem[i][rem];
    int op1=solve(i+1,rem);
    int op2=rem-arr[i]>=0?solve(i+1,rem-arr[i]):1000000000;
    return mem[i][rem]=min(op1,op2);
}
int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int sum=0;
        for(int i=0;i<n;++i)
            scanf("%d",arr+i),sum+=arr[i];
        memset(mem,-1,sizeof mem);
        printf("%d\n",solve(0,sum/2)*2+(sum&1));
    }
    return 0;
}
