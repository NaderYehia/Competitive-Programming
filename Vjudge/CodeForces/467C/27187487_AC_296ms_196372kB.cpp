#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=5e3+5,M=1e8,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m,k;
ll arr[N];
ll mem[N][N];

ll solve(int i,int remk){
    if(i>n&&remk!=0) return -1e18;
    if(remk==0||i>n) return 0;
    ll &ret=mem[i][remk];
    if(~ret) return ret;
    ret=solve(i+1,remk);
    if(i+m-1<=n) ret=max(ret,solve(i+m,remk-1)-arr[i-1]+arr[i+m-1]);
    return ret;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;++i)
        scanf("%lld",arr+i),arr[i]+=arr[i-1];
    memset(mem,-1,sizeof mem);
    printf("%lld",solve(0,k));
    return 0;
}
