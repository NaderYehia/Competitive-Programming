#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e4+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m;
int arr[N];

struct BIT{
    vector<int>v;
    BIT(int n){
        v.resize(n);
    }

    ll get(int i){
        int ret=0;
        for(++i;i;i-=i&-i)
            ret+=v[i-1];
        return ret;
    }

    void update(int i,int val){
        for(++i;i<=v.size();i+=i&-i)
            v[i-1]+=val;
    }

};

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        BIT bit(n);
        while(m--){
            int a,b,val;
            scanf("%d%d%d",&a,&b,&val);
            bit.update(a,val);
            bit.update(b+1,-val);
        }
        int q;scanf("%d",&q);
        while(q--){
            int idx;scanf("%d",&idx);
            printf("%lld\n",bit.get(idx));
        }

    }
    return 0;
}
