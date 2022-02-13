#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e5+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m,k;
int f[30],c[30];

ll solve(int i,ll remV){
    if(i==n) return remV<=0?0:(int)1e18;
    return min(solve(i+1,remV),solve(i+1,remV-1ll*t*f[i])+c[i]);
}

int main(){
    //freopen("myfile.txt","w",stdout);
    int tc=1;ll mx=0;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d%d",f+i,c+i),mx+=f[i];
    scanf("%d",&m);
    while(m--){
        scanf("%d%d",&k,&t);
        if(mx*t<k) printf("Case %d: IMPOSSIBLE\n",tc++);
        else printf("Case %d: %lld\n",tc++,solve(0,k));
    }
    return 0;
}
