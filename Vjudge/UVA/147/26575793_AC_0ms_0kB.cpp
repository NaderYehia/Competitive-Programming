#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e4+5,OO=0x3f3f3f3f;
const double eps=1e-6,pi=3.14159265359;
int t,n,k,m,x,y;
int val[]={5,10,20,50,100,200,500,1000,2000,5000,10000};
ll mem[15][30005];

ll solve(int i,int rem){
    if(i==11){
        return rem==0;
    }
    ll &ret=mem[i][rem];
    if(ret!=-1) return ret;
    ll op1=solve(i+1,rem);
    ll op2=rem-val[i]>=0?solve(i,rem-val[i]):0;
    ret=op1+op2;
    return ret;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    memset(mem,-1,sizeof mem);
    while(~scanf("%d.%d",&x,&y),(x+y)){
        int amount=x*100+y;
        printf("%3d.%.2d%17lld\n",x,y,solve(0,amount));
    }
    return 0;
}
