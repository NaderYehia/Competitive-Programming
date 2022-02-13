#include <bits/stdc++.h>

using namespace std;

const int N=1<<18;

struct BIT2D{
    int tree[500][50005];
    void init(){
        memset(tree,0,sizeof tree);
    }
    void add(int i,int j,int val){
        for(++i;i<=500;i+=i&-i)
            for(int jj=j;jj<=50000;jj+=jj&-jj)
                tree[i-1][jj]+=val;
    }
    int get(int i,int j){
        int ret=0;
        for(++i;i;i-=i&-i)
            for(int jj=j;jj;jj-=jj&-jj)
                ret+=tree[i-1][jj];
        return ret;
    }
    int get_range(int si,int sj,int ei,int ej){
        return get(ei,ej)-get(si-1,ej)-get(ei,sj-1)+get(si-1,sj-1);
    }
};
int arr[N];

int bruteforce(int idx,int val){
    int ret=0;
    int st=(idx/500)*500,en=st+500;
    for(int i=st;i<idx;++i){
        if(arr[i]>val) ++ret;
    }
    for(int i=idx+1;i<en;++i){
        if(arr[i]<val) ++ret;
    }
    return ret;
}


int main(){

    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",arr+i);

    BIT2D bit;
    bit.init();
    long long inv=0;
    for(int i=0;i<n;++i){
        bit.add(i/500,arr[i],1);
        inv+=bit.get_range(0,arr[i]+1,i/500,50000);
    }

    int q;
    scanf("%d",&q);
    while(q--){
        int pos,val;
        scanf("%d%d",&pos,&val);
        --pos;
        inv-=bit.get_range(0,arr[pos]+1,pos/500-1,50000);
        inv-=bit.get_range(pos/500+1,1,499,arr[pos]-1);
        inv-=bruteforce(pos,arr[pos]);
        bit.add(pos/500,arr[pos],-1);
        bit.add(pos/500,val,1);
        arr[pos]=val;
        inv+=bruteforce(pos,arr[pos]);
        inv+=bit.get_range(0,arr[pos]+1,pos/500-1,50000);
        inv+=bit.get_range(pos/500+1,1,499,arr[pos]-1);
        printf("%lld\n",inv);
    }

    return 0;
}
