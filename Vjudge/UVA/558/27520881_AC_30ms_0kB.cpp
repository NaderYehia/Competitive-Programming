#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e3+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m,bon[N],dis[N];

struct edge{
    int u,v,c;
}edges[2*N];


void bellman(){
    for(int i=0;i<n;++i)
        dis[i]=OO;
    dis[0]=0;
    for(int i=0;i<2*(n-1);++i){
        for(int j=0;j<m;++j){
            edge &cur=edges[j];
            if(dis[cur.v]>dis[cur.u]+cur.c){
                if(i>=n) dis[cur.v]=-OO;
                else dis[cur.v]=dis[cur.u]+cur.c;
            }
        }
    }
}

void ford(){
    for(int i=0;i<n-1;++i){
        for(int j=0;j<m;++j){
            edge &cur=edges[j];
            if(dis[cur.v]>dis[cur.u]+cur.c){
                dis[cur.v]=dis[cur.u]+cur.c;
            }
        }
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("myfile.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;++i){
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            edges[i]={u,v,c};
        }
        bellman();
        ford();
        if(dis[n-1]<0) printf("possible\n");
        else printf("not possible\n");
    }
    return 0;
}
