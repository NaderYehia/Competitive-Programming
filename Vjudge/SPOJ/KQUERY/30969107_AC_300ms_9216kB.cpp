#include <bits/stdc++.h>

using namespace std;

const int N=1<<16;

int arr[N],sarr[N],n,qs[N<<2],qe[N<<2],qv[N<<2],sq[N<<2],q,qans[N<<2];

struct BIT{
    
    int tree[N];
    void init(){
        memset(tree,0,sizeof tree);
    }
    void add(int pos,int val){
        for(;pos<=n;pos+=pos&-pos)
            tree[pos]+=val;
    }
    int get(int pos){
        int ret=0;
        for(;pos;pos-=pos&-pos)
            ret+=tree[pos];
        return ret;
    }
    int get(int i,int j){
        return get(j)-get(i-1);
    }
};

int main(){

    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",arr+i);
        
    scanf("%d",&q);
    for(int i=0;i<q;++i)
        scanf("%d%d%d",qs+i,qe+i,qv+i);
        
    iota(sarr,sarr+n,0);
    iota(sq,sq+q,0);
    
    sort(sarr,sarr+n,[](int i,int j){
        return arr[i]>arr[j];
    });
    sort(sq,sq+q,[](int i,int j){
        return qv[i]>qv[j];
    });

    
    BIT bit;
    bit.init();
    int idx=0;
    for(int i=0;i<q;++i){
        int cur=sq[i];
        while(idx<n&&arr[sarr[idx]]>qv[cur]) bit.add(sarr[idx]+1,1),++idx;
        qans[cur]=bit.get(qs[cur],qe[cur]);
    }
    
    for(int i=0;i<q;++i)
        printf("%d\n",qans[i]);

    return 0;
}
