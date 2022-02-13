#include <bits/stdc++.h>

using namespace std;

const int N=1<<18;

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
    int kth(int t){
        int st=0;
        for(int sz=N>>1;sz;sz>>=1){
            if(tree[st+sz-1]<t){
                t-=tree[(st+=sz)-1];
            }
        }
        return st;
    }
}bit;

char op[N];
int x[N],unmp[N];

int main(){

    int q;
    scanf("%d",&q);
    map<int,int> mp;
    for(int i=0;i<q;++i){
        scanf(" %c%d",op+i,x+i);
        if(op[i]!='K') mp[x[i]];
    }

    int id=0;
    for(auto &thing : mp) unmp[id]=thing.first,thing.second=id++;
    
    bit.init();
    for(int i=0;i<q;++i){
        if(op[i]=='I'){
            if(bit.get(mp[x[i]],mp[x[i]])!=1)
                bit.add(mp[x[i]],1);
        }
        else if(op[i]=='D'){
            if(bit.get(mp[x[i]],mp[x[i]]))
                bit.add(mp[x[i]],-1);
        }
        else if(op[i]=='C'){
            printf("%d\n",bit.get(mp[x[i]]-1));
        }
        else{
            if(bit.get(id-1)<x[i]) printf("invalid\n");
            else printf("%d\n",unmp[bit.kth(x[i])]);
        }
    }
    
    return 0;
}
