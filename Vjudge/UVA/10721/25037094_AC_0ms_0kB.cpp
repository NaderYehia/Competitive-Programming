#include<bits/stdc++.h>

using namespace std;

const int N=1e2+5;
int t,n,k,m,x;
long long mem[55][55][55];

long long BC(int n,int k,int m){
    if(k==0){
        if(n==0)
            return 1;
        return 0;
    }
    if(mem[n][k][m]!=-1)    return mem[n][k][m];
    long long ret=0;
    for(int i=1;i<=m&&i<=n;++i){
        ret+=BC(n-i,k-1,m);
    }
    return mem[n][k][m]=ret;
}

int main() {
    memset(mem,-1,sizeof mem);
    while(~scanf("%d%d%d",&n,&k,&m)){
        printf("%lld\n",BC(n,k,m));
    }
    return 0;
}
