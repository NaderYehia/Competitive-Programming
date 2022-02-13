#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e4+10,M=2e4+7,OO=0x3f3f3f3f;

int n,k;
bool mat[50][50];
int mem[15][1<<10];

int solve(int u,int msk){
    if(msk==(1<<n)-1) return !mat[u][0];
    int &ret=mem[u][msk];
    if(~ret) return ret;
    ret=0;
    for(int i=0;i<n;++i){
        if((1<<i)&msk||mat[u][i]) continue;
        ret=(ret+solve(i,msk|(1<<i))%9901)%9901;
    }
    return ret;
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int t,tc=1;
    scanf("%d",&t);
    while(t--){
        memset(mat,0,sizeof mat);
        memset(mem,-1,sizeof mem);
        scanf("%d%d",&n,&k);
        for(int i=0;i<k;++i){
            int u,v;
            scanf("%d%d",&u,&v);
            --u,--v;
            mat[u][v]=mat[v][u]=1;
        }
        printf("Case #%d: %d\n",tc++,(solve(0,1)*4951)%9901);
    }

    return 0;
}
