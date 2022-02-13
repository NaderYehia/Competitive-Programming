#include<bits/stdc++.h>

using namespace std;

const int N=2e3+5;
int t,n;
int h[N],w[N];
long long mem[N];

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
        memset(mem,0,sizeof mem);
        for(int i=0;i<n;++i){
            long long ret=w[i];
            for(int j=0;j<i;++j){
                if(h[j]<h[i])
                    ret=max(ret,w[i]+mem[j]);
            }
            mem[i]=ret;
            ls=max(ls,mem[i]);
        }
        memset(mem,0,sizeof mem);
        for(int i=0;i<n;++i){
            long long ret=w[i];
            for(int j=0;j<i;++j){
                if(h[j]>h[i])
                    ret=max(ret,w[i]+mem[j]);
            }
            mem[i]=ret;
            ds=max(ds,mem[i]);
        }
        if(ds>ls)
            printf("Case %d. Decreasing (%lld). Increasing (%lld).\n",tc++,ds,ls);
        else
            printf("Case %d. Increasing (%lld). Decreasing (%lld).\n",tc++,ls,ds);
    }
    return 0;
}
