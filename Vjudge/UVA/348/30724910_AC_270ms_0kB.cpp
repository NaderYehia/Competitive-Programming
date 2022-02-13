#include <bits/stdc++.h>

using namespace std;

const int N=20+5;

int n;
int r[N],c[N];
long long mem[N][N];

long long solve(int ss,int se){
    if(ss==se) return 0;
    if(mem[ss][se]!=-1) return mem[ss][se];

    long long ret=LONG_LONG_MAX;
    for(int k=ss;k<se;++k){
        ret=min(ret,solve(ss,k)+solve(k+1,se)+1ll*r[ss]*c[se]*c[k]);
    }
    return ret;
}

void dfs(int ss,int se){
    if(ss==se){
        printf("A%d",ss+1);
        return;
    }

    long long ret=solve(ss,se);
    for(int k=ss;k<se;++k){
        if(ret==solve(ss,k)+solve(k+1,se)+1ll*r[ss]*c[se]*c[k]){

            if(ss!=k) printf("(");
            dfs(ss,k);
            if(ss!=k) printf(")");

            printf(" x ");

            if(k+1!=se) printf("(");
            dfs(k+1,se);
            if(k+1!=se) printf(")");

            return;
        }
    }
}

int main(){

    int tc=1;
    while(scanf("%d",&n),n){
        for(int i=0;i<n;++i)
            scanf("%d%d",r+i,c+i);
        memset(mem,-1,sizeof mem);

        printf("Case %d: ",tc++);
        printf("(");
        dfs(0,n-1);
        printf(")\n");
    }


    return 0;
}
