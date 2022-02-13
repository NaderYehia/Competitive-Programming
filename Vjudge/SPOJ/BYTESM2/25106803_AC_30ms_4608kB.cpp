#include<bits/stdc++.h>

using namespace std;

int t,h,w;
int grid[105][105];
int mem[105][105];

bool valid(int v){
    return v>-1&&v<w;
}

int solve(int u,int v){
    if(u==h)
        return 0;
    if(mem[u][v]!=-1) return mem[u][v];
    int op1=solve(u+1,v)+grid[u][v];
    int op2=valid(v-1)?solve(u+1,v-1)+grid[u][v]:-1000000000;
    int op3=valid(v+1)?solve(u+1,v+1)+grid[u][v]:-1000000000;
    return mem[u][v]=max(op1,max(op2,op3));
}

int main() {
    scanf("%d",&t);
    while(t--){
       scanf("%d%d",&h,&w);
       for(int i=0;i<h;++i){
            for(int j=0;j<w;++j)
                scanf("%d",grid[i]+j);
        }
        memset(mem,-1,sizeof mem);
        int mx=0;
        for(int i=0;i<w;++i){
            mx=max(mx,solve(0,i));
        }
        printf("%d\n",mx);
    }
    return 0;
}
