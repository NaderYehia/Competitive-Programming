#include<bits/stdc++.h>

using namespace std;

int t,n;
int arr[100005];
int frq[100005];
long long mem[100005];

long long solve(int i){
    if(i>=100001){
        return 0;
    }
    if(mem[i]!=-1) return mem[i];
    long long op1=solve(i+1);
    long long op2=solve(i+2)+i*1ll*frq[i];
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
