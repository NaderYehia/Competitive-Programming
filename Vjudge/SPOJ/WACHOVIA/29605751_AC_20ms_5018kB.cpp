#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e3+10,M=2e4+7,OO=0x3f3f3f3f;

int mem[50][N],w[50],v[50];

int solve(int i,int rem){
    if(i==-1) return 0;
    int &ret=mem[i][rem];
    if(~ret) return ret;
    ret=solve(i-1,rem);
    if(rem-w[i]>=0) ret=max(ret,solve(i-1,rem-w[i])+v[i]);
    return ret;
}


int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);


    int t;
    scanf("%d",&t);
    while(t--){
        int W,n;
        scanf("%d%d",&W,&n);
        for(int i=0;i<n;++i)
            scanf("%d%d",w+i,v+i);
        memset(mem,-1,sizeof mem);
        printf("Hey stupid robber, you can get %d.\n",solve(n-1,W));
    }

    return 0;
}
