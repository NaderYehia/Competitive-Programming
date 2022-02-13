#include<bits/stdc++.h>

using namespace std;

const int N=2e3+5;
int t,n,m;
int mem[200][200];

int solve(int rem,int k){
    if(rem==0&&k==0)
        return 1;
    if(rem<0||k<0)  return 0;
    if(~mem[rem][k])    return mem[rem][k];
    int ret=0;
    for(int i=0;i<=rem;++i)
        ret=(ret%1000000+solve(rem-i,k-1)%1000000)%1000000;
    return mem[rem][k]=ret;
}

int main() {
    memset(mem,-1,sizeof mem);
    while(scanf("%d%d",&n,&m),(n+m)){
        printf("%d\n",solve(n,m));
    }

    return 0;
}
