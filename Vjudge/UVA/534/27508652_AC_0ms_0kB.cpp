#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=2e2+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m,q;
int x[N],y[N];
bool vis[N];

double dis(int i,int j){
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}

bool can(double x,int u){
    if(u==1) return 1;
    vis[u]=1;
    bool ret=0;
    for(int i=0;i<n;++i){
        if(!vis[i]&&dis(u,i)<=x)
            ret|=can(x,i);
    }
    return ret;
}

double bs(){
    double lo=0.0,hi=1e4,md;
    while(hi-lo>eps){
        md=(hi+lo)/2;
        memset(vis,0,sizeof vis);
        if(can(md,0)) hi=md;
        else lo=md;
    }
    return lo;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("myfile.txt","w",stdout);
    int tc=1;
    while(~scanf("%d",&n),n){
        for(int i=0;i<n;++i)
            scanf("%d%d",x+i,y+i);
        printf("Scenario #%d\n",tc++);
        printf("Frog Distance = %.3f\n\n",bs());
    }
    return 0;
}
