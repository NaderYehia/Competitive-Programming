#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
const int N=2e5+5,M=1e9+7,OO=0x3f3f3f3f;
int n,m,s,t;

int mat[105][105];
int path[105],len;
int vis[105],vid;

int getPath(int s,int t,int id,int mx){

    path[id]=s;

    if(s==t){
        len=id+1;
        return mx;
    }

    vis[s]=vid;
    int ret=0;

    for(int i=0;i<n;++i){

        if(vis[i]==vid||mat[s][i]<=0) continue;

        ret=getPath(i,t,id+1,min(mx,mat[s][i]));

        if(ret>0) break;
    }

    return ret;
}

int maxflow(int s,int t){

    int tot_flow=0;

    while(1){

        ++vid;

        int new_flow=getPath(s,t,0,INT_MAX);

        if(new_flow==0) break;

        for(int i=1;i<len;++i){
            int u=path[i-1],v=path[i];
            mat[u][v]-=new_flow;
            mat[v][u]+=new_flow;
        }

        tot_flow+=new_flow;

    }

    return tot_flow;
}

int main(){
    //freopen("input.in","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("myfile.txt","w",stdout);

    int tc=1;
    while(~scanf("%d",&n),n){
        for(int i=0;i<n;++i)
            memset(mat[i],0,n*sizeof mat[i][0]);
        scanf("%d%d%d",&s,&t,&m);
        for(int i=0;i<m;++i){
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            --u,--v;
            mat[u][v]+=c;
            mat[v][u]+=c;
        }
        printf("Network %d\n",tc++);

        printf("The bandwidth is %d.\n\n",maxflow(--s,--t));

    }
    return 0;
}
