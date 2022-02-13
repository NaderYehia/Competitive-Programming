#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=2e2+10,M=2e4+7,OO=0x3f3f3f3f;

int n;
ll mem[30][10];

ll solve(int i,int msk){
    if(i==n) return msk==0;
    ll &ret=mem[i][msk];
    if(~ret) return ret;
    if(msk==0){
        ret=solve(i+1,7)+solve(i+1,1)+solve(i+1,4);
    }
    else if(msk==1){
        ret=solve(i+1,0)+solve(i+1,6);
    }
    else if(msk==3){
        ret=solve(i+1,4);
    }
    else if(msk==4){
        ret=solve(i+1,0)+solve(i+1,3);
    }
    else if(msk==6){
        ret=solve(i+1,1);
    }
    else{
        ret=solve(i+1,0);
    }
    return ret;
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    while(~scanf("%d",&n),~n){
        memset(mem,-1,sizeof mem);
        printf("%lld\n",solve(0,0));
    }

    return 0;
}
