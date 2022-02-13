#include<bits/stdc++.h>

using namespace std;

const int N=2e3+5;
int t,n;
int h[N],w[N];
long long mem[N];

long long lis(int lst){
    if(mem[lst]!=-1) return mem[lst];
    long long ret=w[lst];
    for(int i=0;i<lst;++i)
        if(h[i]<h[lst])
            ret=max(ret,lis(i)+w[lst]);
    return mem[lst]=ret;
}

long long dis(int lst){
    if(mem[lst]!=-1) return mem[lst];
    long long ret=w[lst];
    for(int i=0;i<lst;++i)
        if(h[i]>h[lst])
            ret=max(ret,dis(i)+w[lst]);
    return mem[lst]=ret;
}

int main() {
    int tc=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%d",h+i);
        for(int i=0;i<n;++i)
            scanf("%d",w+i);
        long long ls=0,ds=0;
        memset(mem,-1,sizeof mem);
        for(int i=0;i<n;++i)
            ls=max(ls,lis(i));
        memset(mem,-1,sizeof mem);
        for(int i=0;i<n;++i)
            ds=max(ds,dis(i));
        if(ds>ls)
            printf("Case %d. Decreasing (%lld). Increasing (%lld).\n",tc++,ds,ls);
        else
            printf("Case %d. Increasing (%lld). Decreasing (%lld).\n",tc++,ls,ds);
    }
    return 0;
}
