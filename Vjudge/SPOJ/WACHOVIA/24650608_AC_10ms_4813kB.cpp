#include<bits/stdc++.h>

using namespace std;
double E=2.71828182845904523536;
double PI=3.14159265358979323846;
int w[1005],v[1005];
int mem[50][1001];

int solve(int idx,int remw){
    if(idx==-1)
        return 0;
    if(mem[idx][remw]!=-1)
        return mem[idx][remw];
    return mem[idx][remw]=max(solve(idx-1,remw),remw-w[idx]>=0?v[idx]+solve(idx-1,remw-w[idx]):(int)-1e9);
}

int main() {
    int t,n,W;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&W,&n);
        for(int i=0;i<n;++i)
            scanf("%d%d",w+i,v+i);
        memset(mem,-1,sizeof mem);
        printf("Hey stupid robber, you can get %d.",solve(n-1,W));
        if(t)
            printf("\n");
    }
	return 0;
}
