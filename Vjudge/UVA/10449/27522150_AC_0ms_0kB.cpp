#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=2e2+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m,q;
ll arr[N],dis[N];

struct edge{
    int u,v;
}edges[N*N];

void bellman(){
    dis[0]=0;
    for(int i=0;i<2*(n-1);++i){
        for(int j=0;j<m;++j){
            edge &cur=edges[j];
            if(dis[cur.u]==1e17) continue;
            ll addh=arr[cur.v]-arr[cur.u];
            addh=addh*addh*addh;
            if(dis[cur.v]>dis[cur.u]+addh){
                if(i>=n) dis[cur.v]=-OO;
                else dis[cur.v]=dis[cur.u]+addh;
            }
        }
    }
}

void ford(){
    for(int i=0;i<n-1;++i){
        for(int j=0;j<m;++j){
            edge &cur=edges[j];
            if(dis[cur.u]==1e17) continue;
            ll addh=arr[cur.v]-arr[cur.u];
            addh=addh*addh*addh;
            if(dis[cur.v]>dis[cur.u]+addh){
                dis[cur.v]=dis[cur.u]+addh;
            }
        }
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("myfile.txt","w",stdout);
    int tc=1;
    while(cin>>n){
        for(int i=0;i<n;++i)
            scanf("%lld",arr+i),dis[i]=1e17;
        scanf("%d",&m);
        for(int i=0;i<m;++i){
            int u,v;
            scanf("%d%d",&u,&v);
            --u,--v;
            edges[i]={u,v};
        }
        bellman();
        ford();
        printf("Set #%d\n",tc++);
        scanf("%d",&q);
        while(q--){
            int dest;
            scanf("%d",&dest);
            --dest;
            if(dis[dest]<3||dis[dest]==1e17) printf("?\n");
            else printf("%d\n",dis[dest]);
        }
    }
    return 0;
}