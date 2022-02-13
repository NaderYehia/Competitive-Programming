#include<bits/stdc++.h>

using namespace std;

int n,w[10000];
long long mem[10000];

long long solve(int lst){
    if(lst<0)
        return 0;
    if(mem[lst]!=-1) return mem[lst];
    return mem[lst]=max(w[lst]+solve(lst-2),solve(lst-1));
}

int main() {
    int t,caseno=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%d",w+i);
        memset(mem,-1,sizeof mem);
        printf("Case %d: %lld",caseno++,solve(n-1));
        if(t)
            printf("\n");
    }
	return 0;
}
