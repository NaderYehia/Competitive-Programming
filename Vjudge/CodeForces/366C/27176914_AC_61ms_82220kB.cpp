#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e5+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m;
int a[105],b[105];
int mem[105][2*N];

int solve(int i,int sum){
    if(i==n) return sum==N?0:(int)-1e9;
    int &ret=mem[i][sum];
    if(~ret) return ret;
    ret=max(solve(i+1,sum),solve(i+1,sum+a[i]-b[i])+a[i]);
    return ret;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
        scanf("%d",a+i);
    for(int i=0;i<n;++i)
        scanf("%d",b+i),b[i]*=m;
    memset(mem,-1,sizeof mem);
    int ans=solve(0,N);
    printf("%d",ans?ans:-1);
    return 0;
}
