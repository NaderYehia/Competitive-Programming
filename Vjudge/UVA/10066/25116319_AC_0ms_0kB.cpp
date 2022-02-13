#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;
int n,m;
int mem[105][105];
int s1[105],s2[105];

int solve(int i,int j){
    if(i==n||j==m)
        return 0;
    if(mem[i][j]!=-1) return mem[i][j];
    if(s1[i]==s2[j])
        return 1+solve(i+1,j+1);
    int op1=solve(i+1,j);
    int op2=solve(i,j+1);
    return mem[i][j]=max(op1,op2);
}

int main() {
    int tc=1;
    while(~scanf("%d%d",&n,&m),(n+m)){
        for(int i=0;i<n;++i)
            scanf("%d",s1+i);
        for(int i=0;i<m;++i)
            scanf("%d",s2+i);
        memset(mem,-1,sizeof mem);
        printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",tc++,solve(0,0));
    }
    return 0;
}