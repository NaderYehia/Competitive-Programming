#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=5e3+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m,k;
ll arr[N];
ll mem[N][N];

ll solve(int i,int used){
    if(i>n) return used==k?0:-1e17;
    ll &ret=mem[i][used];
    if(~ret) return ret;
    ret=-1e17;
    ret=max(ret,solve(i+1,used));
    if(i+m-1<=n) ret=max(ret,solve(i+m,used+1)+arr[i+m-1]-arr[i-1]);
    return ret;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;++i)
        scanf("%lld",arr+i);
    for(int i=1;i<=n;++i) arr[i]+=arr[i-1];
    memset(mem,-1,sizeof mem);
    printf("%lld",solve(1,0));
    return 0;
}
