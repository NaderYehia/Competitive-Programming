#include <bits/stdc++.h>

using namespace std;

const int N=1<<17,MOD=5000000;

struct BIT{
    long long tree[N];

    void init(){
        memset(tree,0,sizeof tree);
    }
    void add(int i,int val){
        for(++i;i<=N;i+=i&-i)
            tree[i]=(tree[i]+val)%MOD;
    }
    long long get(int i){
        long long ret=0;
        for(++i;i;i-=i&-i)
            ret=(ret+tree[i])%MOD;
        return ret;
    }
    long long get_range(int i,int j){
        return get(j)-get(i-1);
    }
}bit[55];

int arr[N],n,k;;

int main(){

    scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i)
        scanf("%d",arr+i);

    for(int i=0;i<55;++i) bit[i].init();

    for(int i=0;i<n;++i){
        for(int j=1;j<=k;++j){
            bit[j].add(arr[i],bit[j-1].get(arr[i]-1));
        }
        bit[1].add(arr[i],1);
    }

    printf("%lld\n",bit[k].get(100000));

    return 0;
}
