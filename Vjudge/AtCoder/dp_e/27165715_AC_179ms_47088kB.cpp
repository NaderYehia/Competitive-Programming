#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e3+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,W;
int p[N],w[N];
int mem[105][105*N];

int solve(int i,int remV){
    if(i==n){
        return remV==0?0:(int)1e9;
    }
    int &ret=mem[i][remV];
    if(~ret) return ret;
    ret=solve(i+1,remV);
    ret=min(ret,solve(i+1,remV-p[i])+w[i]);
    return ret;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d%d",&n,&W);
    int sumall=0;
    for(int i=0;i<n;++i)
        scanf("%d%d",w+i,p+i),sumall+=p[i];
    memset(mem,-1,sizeof mem);
    for(int i=sumall;i>=0;--i){
        if(solve(0,i)<=W){
            printf("%d",i);
            break;
        }
    }
    return 0;
}
