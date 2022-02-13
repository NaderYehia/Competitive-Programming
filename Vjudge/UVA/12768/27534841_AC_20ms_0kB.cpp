#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e2+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m,q,dis[N],p[N];

struct edge{
    int u,v,c;
}edges[N*N];

bool bellman(){
    for(int i=0;i<n;++i)
        dis[i]=-OO;
    dis[0]=0;
    for(int i=0;i<2*(n-1);++i){
        for(int j=0;j<m;++j){
            edge &cur=edges[j];
            if(dis[cur.u]==-OO) continue;
            if(dis[cur.v]<dis[cur.u]+cur.c){
                if(i>=n-1) return 1;
                else dis[cur.v]=dis[cur.u]+cur.c,p[cur.v]=cur.u;
            }
        }
    }
    return 0;
}

int print(){
    int ret=0;
    for(int i=0;i<n;++i)
        ret=max(ret,dis[i]);
    return ret;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("myfile.txt","w",stdout);
    while(~scanf("%d%d",&n,&m),n+m){
        for(int i=0;i<m;++i){
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            --u,--v;
            edges[i]={u,v,c};
        }
        if(bellman()) printf("Unlimited!\n");
        else printf("%d\n",print());
    }
    return 0;
}
