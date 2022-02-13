#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e3+10,M=2e4+7,OO=0x3f3f3f3f;

int n,ox[N],ni[N],w[N],mem[N][22][80];

int solve(int i,int remo,int remn){
    if(i==-1) return (remo<=0&&remn<=0)?0:OO;
    int &ret=mem[i][remo][remn];
    if(~ret) return ret;
    ret=min(solve(i-1,remo,remn),solve(i-1,max(0,remo-ox[i]),max(0,remn-ni[i]))+w[i]);
    return ret;
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int t;
    scanf("%d",&t);
    while(t--){
        int on,nn;
        scanf("%d%d",&on,&nn);
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%d%d%d",ox+i,ni+i,w+i);
        memset(mem,-1,sizeof mem);
        printf("%d\n",solve(n-1,on,nn));
    }


    return 0;
}
