#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=2e5+5,M=2<<30,OO=0x3f3f3f3f;
int t,n,m,k,W;
int arr[N],qs[N],qe[N],qk[N],qsorted[N],arrsorted[N],ans[N];
 
struct BIT{
    vector<int> v;
    int sz;
 
    BIT(int n){
        v.resize(n);
        sz=n;
    }
 
    int get(int i){
        int ret=0;
        ++i;
        while(i){
            ret+=v[i-1];
            i-=i&-i;
        }
        return ret;
    }
 
    void update(int i,int val){
        ++i;
        while(i<=sz){
            v[i-1]+=val;
            i+=i&-i;
        }
    }
 
    int query(int a,int b){
        return get(b)-get(a-1);
    }
 
};
 
int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",arr+i),arrsorted[i]=i;
    sort(arrsorted,arrsorted+n,[](int i,int j){
         return arr[i]>arr[j];
         });
    scanf("%d",&m);
    for(int i=0;i<m;++i)
        scanf("%d%d%d",qs+i,qe+i,qk+i),qsorted[i]=i;
    sort(qsorted,qsorted+m,[](int i,int j){
        return qk[i]>qk[j];
        });
    BIT bit(n);
    int j=0;
    for(int i=0;i<m;++i){
        int tmp=qk[qsorted[i]];
        while(j<n&&tmp<arr[arrsorted[j]]){
            bit.update(arrsorted[j],1);
            ++j;
        }
        ans[qsorted[i]]=bit.query(qs[qsorted[i]]-1,qe[qsorted[i]]-1);
    }
    for(int i=0;i<m;++i)
        printf("%d\n",ans[i]);
    return 0;
}