#include<bits/stdc++.h>

using namespace std;

const int N=1e2+5;
int t,n,b;
int cur[306];
long long mem[305][305][1005];

long long solve(int n,int i,int k){
    if(i==301){
        if(n==0&&k==0)
            return 1;
        return 0;
    }
    if(mem[n][i][k]!=-1)    return mem[n][i][k];
    long long op1=n-i>=0?solve(n-i,i,k-1):0;
    long long op2=solve(n,i+1,k);
    return mem[n][i][k]=op1+op2;
}

int main() {
    memset(mem,-1,sizeof mem);
    string s;
    while(getline(cin,s)){
        stringstream ss(s);
        int n=-1,b=-1,c=-1;
        if(ss>>n);
        if(ss>>b);
        if(ss>>c);
        long long ans=0;
        if(b==-1&&c==-1){
            for(int i=0;i<=n;++i)
                ans+=solve(n,1,i);
        }
        else if(c==-1){
            for(int i=0;i<=b;++i)
                ans+=solve(n,1,i);
        }
        else{
            for(int i=b;i<=c;++i)
                ans+=solve(n,1,i);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
