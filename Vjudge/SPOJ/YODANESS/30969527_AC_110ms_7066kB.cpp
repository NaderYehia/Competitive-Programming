#include <bits/stdc++.h>

using namespace std;

const int N=1<<16;

int t,n;

struct BIT{
    int tree[N];
    void init(){
        memset(tree,0,sizeof tree);
    }
    void add(int pos,int val){
        for(++pos;pos<=n;pos+=pos&-pos)
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

    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vector<string> v(n);
        for(int i=0;i<n;++i)
            cin>>v[i];
        
        map<string,int> mp;
        for(int i=0;i<n;++i){
            string s;
            cin>>s;
            mp[s]=i;
        }
        vector<int> arr(n);
        for(int i=0;i<n;++i)
            arr[i]=mp[v[i]];
        
        bit.init();
        
        long long ans=0;
        for(int i=0;i<n;++i){
            ans+=bit.get(arr[i],n-1);
            bit.add(arr[i],1);
        }
        printf("%lld\n",ans);
    }
    
    return 0;
}
