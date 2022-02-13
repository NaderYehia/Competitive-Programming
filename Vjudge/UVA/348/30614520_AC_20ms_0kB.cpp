#include <bits/stdc++.h>

using namespace std;

const int N=2e3+10;

int n;
int r[15],c[15];

int mem[15][15];


long long solve(int ss,int se){
    if(ss==se) return 0;
    if(mem[ss][se]!=-1) return mem[ss][se];

    long long ret=LONG_LONG_MAX;
    for(int i=ss;i<se;++i){
        long long cur=solve(ss,i)+solve(i+1,se)+r[ss]*c[i]*c[se];
        ret=min(ret,cur);
    }
    return mem[ss][se]=ret;
}

void dfs(int ss,int se){
    if(ss==se){
        printf("A%d",ss+1);
        return;
    }

    long long ret=solve(ss,se);
    for(int i=ss;i<se;++i){
        long long cur=solve(ss,i)+solve(i+1,se)+r[ss]*c[i]*c[se];
        if(ret==cur){

            if(ss!=i) printf("(");
            dfs(ss,i);
            if(ss!=i) printf(")");

            printf(" x ");

            if(i+1!=se) printf("(");
            dfs(i+1,se);
            if(i+1!=se) printf(")");

            return;
        }
    }
}

int main()
{

    int tc=1;
    while(scanf("%d",&n),n){
        for(int i=0;i<n;++i)
            scanf("%d%d",r+i,c+i);

        memset(mem,-1,sizeof mem);

        printf("Case %d: ",tc++);
        printf("(");
        dfs(0,n-1);
        printf(")");
        printf("\n");
    }

    return 0;
}
