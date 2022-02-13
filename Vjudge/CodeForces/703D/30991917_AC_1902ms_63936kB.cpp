#include <bits/stdc++.h>

using namespace std;

const int N=1<<20;

struct BIT{
    int tree[N];
    void init(){
        memset(tree,0,sizeof tree);
    }
    void add(int pos,int val){
        for(;pos<=N;pos+=pos&-pos)
            tree[pos-1]^=val;
    }
    int get(int pos){
        int ret=0;
        for(;pos;pos-=pos&-pos)
            ret^=tree[pos-1];
        return ret;
    }
    int get(int i,int j){
        return get(j)^get(i-1);
    }

}bit;

int arr[N],pre[N],qs[N],qe[N],sq[N],qans[N];

int main(){

    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",arr+i);
        
    for(int i=1;i<=n;++i)
        pre[i]=pre[i-1]^arr[i];

    int m;
    scanf("%d",&m);
    for(int i=0;i<m;++i)
        scanf("%d%d",qs+i,qe+i);
    
    iota(sq,sq+m,0);
    sort(sq,sq+m,[](int i,int j){
        return qe[i]<qe[j];
    });
    
    map<int,int> last;
    bit.init();
    int idx=1;
    for(int i=0;i<m;++i){
        int cq=sq[i];
        while(idx<=n&&idx<=qe[cq]){
            if(last.find(arr[idx])!=last.end()) bit.add(last[arr[idx]],arr[idx]);
            last[arr[idx]]=idx;
            bit.add(idx,arr[idx]);
            ++idx;
        }
        qans[sq[i]]=(pre[qe[cq]]^pre[qs[cq]-1])^bit.get(qs[cq],qe[cq]);
    }

    for(int i=0;i<m;++i)
        printf("%d\n",qans[i]);
    
    
    return 0;
}
