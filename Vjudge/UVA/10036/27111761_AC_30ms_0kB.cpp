#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e4+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int n,m,a[N];
int mem[N][105];

int solve(int i,int sum){
    if(i==n) return sum==0;
    int &ret=mem[i][sum];
    if(~ret) return ret;
    ret=solve(i+1,(sum+a[i])%m)||solve(i+1,(sum-a[i])%m);
    return ret;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;++i)
            scanf("%d",a+i),a[i]%=m;
        memset(mem,-1,sizeof mem);
        printf("%s\n",solve(1,a[0])?"Divisible":"Not divisible");
    }
    return 0;
}
