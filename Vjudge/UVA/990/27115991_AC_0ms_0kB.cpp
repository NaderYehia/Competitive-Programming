#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e4+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,w,n,d[50],v[50],td[50];
ll mem[50][1005];
vector<int>tmp;

ll solve(int i,int remT){
    if(i==n) return 0;
    ll &ret=mem[i][remT];
    if(~ret) return ret;
    ret=max(solve(i+1,remT),remT-td[i]>=0?solve(i+1,remT-td[i])+v[i]:(int)-1e9);
    return ret;
}

void dfs(int i,int remT){
    if(i==n) return;
    ll ret=mem[i][remT];
    if(ret==solve(i+1,remT)){
        dfs(i+1,remT);
    }
    else{
        tmp.push_back(i);
        dfs(i+1,remT-td[i]);
    }
}

int main(){
    //freopen("myfile.txt","w",stdout);
    int tc=0;
    while(scanf("%d%d",&t,&w)==2){
        if(tc++) printf("\n");
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%d%d",d+i,v+i),td[i]=3*w*d[i];
        tmp.clear();
        memset(mem,-1,sizeof mem);
        printf("%lld\n",solve(0,t));
        dfs(0,t);
        printf("%d\n",tmp.size());
        for(int i=0;i<tmp.size();++i)
            printf("%d %d\n",d[tmp[i]],v[tmp[i]]);
    }
    return 0;
}
