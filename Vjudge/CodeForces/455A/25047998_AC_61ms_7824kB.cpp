#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;
int t,n;
int arr[N];
int frq[N];
long long mem[N];

long long solve(int i){
    if(i>100000)
        return 0;
    if(mem[i]!=-1) return mem[i];
    long long op1=solve(i+1);
    long long op2=solve(i+2)+(i*1ll*frq[i]);
    return mem[i]=max(op1,op2);
}

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",arr+i),++frq[arr[i]];
    memset(mem,-1,sizeof mem);
    printf("%lld",solve(1));
    return 0;
}
