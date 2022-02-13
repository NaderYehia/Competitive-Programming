#include<bits/stdc++.h>

using namespace std;

const int N=1e5;
int n;
int arr[N];
int mem[N];

int solve(int i){
    if(i==n-1)
        return 0;
    if(mem[i]!=-1) return mem[i];
    int op1=solve(i+1)+abs(arr[i]-arr[i+1]);
    int op2=i+2<=n-1?solve(i+2)+abs(arr[i]-arr[i+2]):1000000000;
    return mem[i]=min(op1,op2);
}

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",arr+i);
    memset(mem,-1,sizeof mem);
    printf("%d",solve(0));
    return 0;
}
