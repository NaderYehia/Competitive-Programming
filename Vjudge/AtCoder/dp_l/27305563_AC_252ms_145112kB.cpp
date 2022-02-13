#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=3e3+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,a[N];
ll mem[N][N][2];

ll solve(int i,int j,int p){
    if(i>j) return 0;
    ll &ret=mem[i][j][p];
    if(~ret) return ret;
    if(!p){
        ret=max(a[i]+solve(i+1,j,1),a[j]+solve(i,j-1,1));
    }
    else{
        ret=min(-a[i]+solve(i+1,j,0),-a[j]+solve(i,j-1,0));
    }
    return ret;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",a+i);
    memset(mem,-1,sizeof mem);
    printf("%lld",solve(0,n-1,0));
    return 0;
}
