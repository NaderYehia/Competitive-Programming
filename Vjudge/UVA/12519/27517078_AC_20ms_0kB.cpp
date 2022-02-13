#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e2+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m,q;
int dis[N];
struct edge{
    int u,v,c;
}edges[N*N];

bool solve(){
    for(int i=0;i<n;++i)
        dis[i]=-OO;
    dis[0]=0;
    for(int i=0;i<=2*(n-1);++i){
        for(int j=0;j<m;++j){
            edge &cur=edges[j];
            if(dis[cur.v]<dis[cur.u]+cur.c){
                if(cur.v==0) return 1;
                dis[cur.v]=dis[cur.u]+cur.c;
            }
        }
    }
    return 0;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("myfile.txt","w",stdout);
    int tc=1;
    while(~scanf("%d%d",&n,&m),n+m){
        m*=2;
        for(int i=0;i<m;i+=2){
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            --u,--v;
            edges[i]={u,v,c};
            edges[i+1]={v,u,-c};
        }
        printf(solve()?"Y\n":"N\n");
    }
    return 0;
}
