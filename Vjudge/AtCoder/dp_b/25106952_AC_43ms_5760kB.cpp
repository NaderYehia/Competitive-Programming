#include<bits/stdc++.h>

using namespace std;

const int N=1e5;
int n,k;
int arr[N];
int mem[N];

int solve(int i){
    if(i==n-1)
        return 0;
    if(mem[i]!=-1) return mem[i];
    int ret=1000000000;
    for(int j=1;j<=k;++j){
        ret=min(ret,j+i<=n-1?solve(i+j)+abs(arr[i]-arr[i+j]):1000000000);
    }
    return mem[i]=ret;
}

int main() {
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i)
        scanf("%d",arr+i);
    memset(mem,-1,sizeof mem);
    printf("%d",solve(0));
    return 0;
}
