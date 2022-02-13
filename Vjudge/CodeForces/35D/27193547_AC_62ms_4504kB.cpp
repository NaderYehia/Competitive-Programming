#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e5+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m,k;
int arr[105];
int mem[105][10005];

int solve(int i,int remF){
    if(i==n) return 0;
    int &ret=mem[i][remF];
    if(~ret) return ret;
    ret=solve(i+1,remF);
    int nwF=remF-((n-i)*arr[i]);
    if(nwF>=0) ret=max(ret,solve(i+1,nwF)+1);
    return ret;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    freopen("output.txt","w",stdout);
    freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i)
        scanf("%d",arr+i);
    memset(mem,-1,sizeof mem);
    printf("%d",solve(0,k));
    return 0;
}
