#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e2+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m,bon[N],dis[N];

struct edge{
    int u,v;
}edges[N*N];

int idx;

void bellman(){
    for(int i=0;i<n;++i)
        dis[i]=0;
    dis[0]=100;
    for(int i=0;i<2*(n-1);++i){
        for(int j=0;j<idx;++j){
            edge &cur=edges[j];
            if(dis[cur.u]>0&&dis[cur.v]<bon[cur.v]+dis[cur.u]){
                if(i>=n) dis[cur.v]=OO;
                else dis[cur.v]=bon[cur.v]+dis[cur.u];
            }
        }
    }
}

void ford(){
    for(int i=0;i<n-1;++i){
        for(int j=0;j<idx;++j){
            edge &cur=edges[j];
            if(dis[cur.u]>0&&dis[cur.v]<bon[cur.v]+dis[cur.u]){
                dis[cur.v]=bon[cur.v]+dis[cur.u];
            }
        }
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("myfile.txt","w",stdout);
    while(~scanf("%d",&n),n!=-1){
        idx=0;
        for(int i=0,c,m,v;i<n;++i){
            scanf("%d%d",&c,&m);
            bon[i]=c;
            while(m--){
                scanf("%d",&v);
                edges[idx++]={i,v-1};
            }
        }
        bellman();
        ford();
        if(dis[n-1]>0) printf("winnable\n");
        else printf("hopeless\n");
    }
    return 0;
}
