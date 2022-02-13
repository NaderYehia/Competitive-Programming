#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=2e3+5,M=1e9+7,OO=0x3f3f3f3f;
const double eps=1e-6,pi=acos(-1);
int t,n,q,d,m;
int arr[]={1,5,10,25,50};
ll mem[10][30005];

ll solve(int i,int rem){
    if(i==5) return rem==0;
    ll &ret=mem[i][rem];
    if(~ret) return ret;
    ll op1=solve(i+1,rem);
    ll op2=rem-arr[i]>=0?solve(i,rem-arr[i]):0;
    ret=op1+op2;
    return ret;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    memset(mem,-1,sizeof mem);
    while(~scanf("%d",&n)){
        ll ans=solve(0,n);
        if(ans==1) printf("There is only %lld way to produce %d cents change.\n",ans,n);
        else printf("There are %lld ways to produce %d cents change.\n",ans,n);
    }
    return 0;
}
