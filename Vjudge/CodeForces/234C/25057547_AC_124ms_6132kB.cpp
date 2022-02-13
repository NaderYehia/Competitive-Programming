#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;
int t,n,c;
int arr[N];
int mem[N][2];

int solve(int i,int pos){
    if(i==n-1)
        return 0;
    if(mem[i][pos]!=-1) return mem[i][pos];
    int ret=0;
    if(pos){
        if(arr[i]<1)
            ret=1+solve(i+1,1);
        else
            ret=solve(i+1,1);
    }
    else{
        ret=solve(i+1,0)+(arr[i]>=0);
        ret=min(ret,solve(i+1,1)+(arr[i]<=0));
    }
    return mem[i][pos]=ret;
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int cnt=0;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",arr+i);
    if(arr[0]>=0)
        ++cnt;
    if(arr[n-1]<=0)
        ++cnt;
    memset(mem,-1,sizeof mem);
    printf("%d",cnt+min(solve(1,0),solve(1,1)));
    return 0;
}
