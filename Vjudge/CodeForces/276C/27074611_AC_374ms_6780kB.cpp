#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=2e5+5,M=1<<30,SEGM=4*N,OO=0x3f3f3f3f;
int n;
int arr[N],frq[N];

struct bit{
    vector<ll> v;
    int sz;
    bit(int n):v(n){}

    ll get(int i){
        ll ret=0;
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
    int q;
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;++i)
        scanf("%d",arr+i);
    bit cm(n);
    while(q--){
        int a,b;
        scanf("%d%d",&a,&b);
        cm.update(--a,1),cm.update(b,-1);
    }
    for(int i=0;i<n;++i)
        frq[i]=cm.get(i);
    sort(arr,arr+n);
    sort(frq,frq+n);
    ll ans=0;
    for(int i=0;i<n;++i)
        ans+=1ll*arr[i]*frq[i];
    printf("%lld",ans);
    return 0;
}
