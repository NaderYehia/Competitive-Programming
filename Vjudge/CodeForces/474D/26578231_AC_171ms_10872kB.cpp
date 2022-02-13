#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e5+5,M=1e9+7,OO=0x3f3f3f3f;
const double eps=1e-6,pi=3.14159265359;
int t,n,k,m;
int mem[N];

int solve(int rem){
    if(rem==0) return 1;
    int &ret=mem[rem];
    if(ret!=-1) return ret;
    int op1=solve(rem-1)%M;
    int op2=rem-k>=0?solve(rem-k)%M:0;
    ret=(op1+op2)%M;
    return ret;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d%d",&n,&k);
    memset(mem,-1,sizeof mem);
    solve(N-1);
    mem[0]=0;
    for(int i=1;i<N;++i)
        mem[i]=(mem[i]+mem[i-1])%M;
    for(int i=0,a,b;i<n;++i){
        scanf("%d%d",&a,&b);
        printf("%d\n",(mem[b]-mem[a-1]+M)%M);
    }
    return 0;
}
