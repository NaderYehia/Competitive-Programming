#include<bits/stdc++.h>

using namespace std;

const int N=1e2+5;
int mon[N];
int fv[N];
int n,m;
int mem[N][400005];

int solve(int i,int paid){
    if(paid>m+200)
        return -1000000;
    if(i==n){
        if(paid>2000){
            if(m+200>=paid)
                return 0;
            return -10000000;
        }
        if(m>=paid)
            return 0;
        return -10000000;
    }
    if(mem[i][paid]!=-1) return mem[i][paid];
    int op1=solve(i+1,paid);
    int op2=solve(i+1,paid+mon[i])+fv[i];
    return mem[i][paid]=max(op1,op2);
}

int main() {
    while(~scanf("%d%d",&m,&n)){
        for(int i=0;i<n;++i)
            scanf("%d%d",mon+i,fv+i);
        memset(mem,-1,sizeof mem);
        printf("%d\n",solve(0,0));
    }
    return 0;
}

