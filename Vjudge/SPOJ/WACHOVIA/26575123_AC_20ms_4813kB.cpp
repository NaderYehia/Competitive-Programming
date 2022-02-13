#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e5+5,OO=0x3f3f3f3f;
const double eps=1e-6,pi=3.14159265359;
int t,n,k,m;
int wt[N];
int val[N];
int mem[60][1006];

int solve(int idx,int rem){
    if(idx==n)
        return 0;
    int &ret=mem[idx][rem];
    if(ret!=-1) return ret;
    ret=max(solve(idx+1,rem),rem>=wt[idx]?solve(idx+1,rem-wt[idx])+val[idx]:(int)-1e9);
    return ret;
}

int main(){
    //freopen("business.in","r",stdin);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&k,&n);
        for(int i=0;i<n;++i)
            scanf("%d%d",wt+i,val+i);
        memset(mem,-1,sizeof mem);
        printf("Hey stupid robber, you can get %d.\n",solve(0,k));
    }
    return 0;
}
