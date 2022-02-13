#include<bits/stdc++.h>

using namespace std;

const int N=2e2+5;
long long arr[N],tmp[N];
int n,d,m,q;
long long mem[N][30][30];

long long solve(int i,int cur,int m){
    if(m<0) return 0;
    if(i==n){
        if(m==0&&cur==0)
            return 1;
        return 0;
    }
    if(mem[i][cur][m]!=-1)  return mem[i][cur][m];
    long long op1=solve(i+1,cur,m);
    long long op2=solve(i+1,(((cur+arr[i])%d)+d)%d,m-1);
    return mem[i][cur][m]=op1+op2;
}

int main() {
    int sets=1,qus=1;
    while(~scanf("%d%d",&n,&q),(n+q)){
        printf("SET %d:\n",sets++);
        for(int i=0;i<n;++i)
            scanf("%lld",arr+i);
        qus=1;
        while(q--){
            scanf("%d%d",&d,&m);
            memset(mem,-1,sizeof mem);
            printf("QUERY %d: %lld\n",qus++,solve(0,0,m));
        }
    }
    return 0;
}
