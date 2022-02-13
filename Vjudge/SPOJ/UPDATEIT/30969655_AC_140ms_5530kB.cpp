#include <bits/stdc++.h>

using namespace std;

const int N=1<<16;

struct BIT{
    int tree[N];
    void init(){
        memset(tree,0,sizeof tree);
    }
    void add(int pos,int val){
        for(++pos;pos<=N;pos+=pos&-pos)
            tree[pos-1]+=val;
    }
    int get(int pos){
        int ret=0;
        for(++pos;pos;pos-=pos&-pos)
            ret+=tree[pos-1];
        return ret;
    }
    int get(int i,int j){
        return get(j)-get(i-1);
    }
}bit;

int main(){

    int t;
    scanf("%d",&t);
    while(t--){
        int n,u;
        scanf("%d%d",&n,&u);
        vector<int> pre(++n);
        while(u--){
            int l,r,val;
            scanf("%d%d%d",&l,&r,&val);
            pre[l]+=val;
            pre[r+1]-=val;
        }
        
        for(int i=1;i<n;++i)
            pre[i]+=pre[i-1];
            
        scanf("%d",&u);
        while(u--){
            int pos;
            scanf("%d",&pos);
            printf("%d\n",pre[pos]);
        }
    }
    
    return 0;
}
